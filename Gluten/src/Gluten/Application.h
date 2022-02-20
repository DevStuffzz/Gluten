#pragma once


#include "Gluten/Core.h"
#include "Gluten/Window.h"
#include "Gluten/LayerStack.h"

#include "Gluten/Events/Event.h"
#include "Gluten/Events/ApplicationEvent.h"

#include "Gluten/Renderer/Shader.h";
#include "Gluten/Renderer/Buffer.h"

namespace Gluten {
	class GLUT_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

		unsigned int m_VertexArray;

		std::unique_ptr<Renderer::Shader> m_Shader;
		std::unique_ptr<Renderer::VertexBuffer> m_VertexBuffer;
		std::unique_ptr<Renderer::IndexBuffer> m_IndexBuffer;
	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

