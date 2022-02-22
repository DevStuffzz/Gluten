#include "glutpch.h"
#include "SwapChain.h"

#include "Renderer.h"
#include <glad/glad.h>

namespace Gluten::Renderer {
	void SwapChain::BeginFrame(float r, float g, float b, float a)
	{

		switch (GlutenRenderer::GetAPI()) {
			case RendererAPI::None: GLUT_CORE_ERROR("RendererAPI::None is not currently supported!"); return;
			case RendererAPI::OpenGL:
				glClearColor(r, g, b, a);
				glClear(GL_COLOR_BUFFER_BIT);
				break;
		}

	}

	void SwapChain::EndFrame()
	{
	}

	void SwapChain::Submit(std::unique_ptr<Renderer::Shader>& shader, std::unique_ptr<Renderer::VertexArray>& vertexArray)
	{
		switch (GlutenRenderer::GetAPI()) {
			case RendererAPI::None: GLUT_CORE_ERROR("RendererAPI::None is not currently supported!"); return;
			case RendererAPI::OpenGL:
				shader->Bind();
				vertexArray->Bind();
				glDrawElements(GL_TRIANGLES, vertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
				vertexArray->Unbind();
				shader->Unbind();
				break;
		}
	}
}