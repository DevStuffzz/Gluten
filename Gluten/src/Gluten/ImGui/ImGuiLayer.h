#pragma once

#include "Gluten/Layer.h"
#include "Gluten/Core.h"

#include "Gluten/Events/KeyEvent.h";
#include "Gluten/Events/MouseEvent.h"
#include "Gluten/Events/ApplicationEvent.h"

namespace Gluten {
	class GLUT_API ImGuiLayer : public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);

	private:
		// Mouse
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMoveEvent(MouseMovedEvent& e);
		bool OnMouseScrollEvent(MouseScrolledEvent& e);
		
		// Keyboard
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);

		// Window Resize
		bool OnWindowResizeEvent(WindowResizeEvent& e);
	private:
		float m_Time = 0.0f;
	};
}