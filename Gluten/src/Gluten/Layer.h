#pragma once
#include "Gluten/Core.h"
#include "Gluten/Events/Event.h"

namespace Gluten {
	class GLUT_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }
	private:
		const std::string& m_DebugName;
	};
}

