#include "glutpch.h"

#include "Gluten/Application.h"
#include "Gluten/Input.h"
#include "Gluten/Log.h"

#include <glad/glad.h>
#include <glm/glm.hpp>

namespace Gluten {
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		GLUT_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent)));
		
		glGenVertexArrays(1, &m_VertexArray);
		glBindVertexArray(m_VertexArray); 

		float vertices[3 * 3] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f
		};

		m_VertexBuffer.reset(Renderer::VertexBuffer::Create(vertices, sizeof(vertices)));
		
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, false, 3 * sizeof(float), nullptr);

		uint32_t indices[3] = {
			0, 1, 2
		};

		m_IndexBuffer.reset(Renderer::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));

		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		std::string vertexSrc = R"(
		#version 330 core

		layout(location=0) in vec3 a_Position;

		out vec3 v_Position;

		void main() {
			v_Position = a_Position;
			gl_Position = vec4(a_Position, 1.0);
		}	
		)";

		std::string fragmentSrc = R"(\
		#version 330 core
		
		out vec4 color;

		in vec3 v_Position;


		void main() {
			color = vec4(v_Position+0.5, 1);
		}	
		)";

		m_Shader.reset(new Renderer::Shader(vertexSrc, fragmentSrc));


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
			glClearColor(0.1, 0.1, 0.1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			m_Shader->Bind();
			glBindVertexArray(m_VertexArray);
			glDrawElements(GL_TRIANGLES, m_IndexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr);
			m_Shader->Unbind();

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