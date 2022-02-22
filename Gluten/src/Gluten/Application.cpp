#include "glutpch.h"

#include "Gluten/Application.h"
#include "Gluten/Input.h"
#include "Gluten/Log.h"

#include "Gluten/Renderer/SwapChain.h"

#include <glad/glad.h>
#include <glm/glm.hpp>

using namespace Gluten::Renderer;

namespace Gluten {
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		GLUT_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent)));
		
		m_VertexArray.reset(Renderer::VertexArray::Create());
		m_VertexArray->Bind();

		float vertices[3 * 4] = {
			-0.75f, -0.75f, 0.0f,
			 0.75f, -0.75f, 0.0f, 
			 0.75f,  0.75f, 0.0f, 
			-0.75f,  0.75f, 0.0f
		};

		
		std::shared_ptr<VertexBuffer> vertexBuffer;
		vertexBuffer.reset(VertexBuffer::Create(vertices, sizeof(vertices)));
		Renderer::BufferLayout layout = {
			{ ShaderDataType::Float3, "a_Position" },
		};
		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indices[6] = {
			0, 1, 2, 2, 3, 0
		};

		std::shared_ptr<IndexBuffer> indexBuffer;
		indexBuffer.reset(IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->AddIndexBuffer(indexBuffer);

		std::string vertexSrc = R"(
		#version 330 core

		layout(location=0) in vec3 a_Position;

		uniform vec4 u_Color;

		out vec4 f_Color;

		void main() {
			gl_Position = vec4(a_Position, 1.0);
			f_Color = u_Color;
		}	
		)";

		std::string fragmentSrc = R"(\
		#version 330 core
		
		out vec4 color;

		in vec4 f_Color;

		void main() {
			float noise = fract(sin(dot(f_Color.xy, vec2(12.9898, 78.233))) * 43758.5435);
			color = f_Color * noise;
		}	
		)";

		m_Shader.reset(new Shader(vertexSrc, fragmentSrc));


;	}

	Application::~Application()
	{
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}
	
	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose)));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}

	void Application::Run()
	{
		while (m_Running)
		{
			SwapChain::BeginFrame(0.1, 0.1, 0.1, 1);
			m_Shader->UploadUniform4f({ 1.0f, 0.0f, 0.0f, 1.0f }, "u_Color");
			SwapChain::Submit(m_Shader, m_VertexArray);
			SwapChain::EndFrame();

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}