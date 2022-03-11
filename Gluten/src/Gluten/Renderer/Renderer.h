#pragma once

#include "GraphicsContext.h"

namespace Gluten::Renderer {
	enum class RendererAPI {
		None = 0, OpenGL = 1, DX3D = 2, Vulkan = 3, Metal = 4
	};

	class GlutenRenderer {
	public:
		inline static RendererAPI GetAPI() { return s_RendererAPI; }
		static RendererAPI s_RendererAPI;
	private:
	};
}