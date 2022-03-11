#pragma once
#include <glm/glm.hpp>

namespace Gluten::Renderer {

	class GraphicsContext {
	public:
		virtual void Init() = 0; 
		virtual void SwapBuffers() = 0;
		virtual void Clear(glm::vec4 color) = 0;
	};

}