#pragma once

#include "Shader.h"
#include "VertexArray.h"

namespace Gluten::Renderer {
	class SwapChain {
	public:
		static void BeginFrame(float r, float g, float b, float a);
		static void EndFrame();

		static void Submit(std::unique_ptr<Renderer::Shader>& shader, std::unique_ptr<Renderer::VertexArray>& vertexArray);
	private:
		SwapChain();
	};
}