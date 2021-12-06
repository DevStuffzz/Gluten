#pragma once

#include "Gluten/Layer.h"
#include "Gluten/Core.h"

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
		float m_Time = 0.0f;
	};
}