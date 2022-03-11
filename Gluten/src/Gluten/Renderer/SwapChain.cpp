#include "glutpch.h"
#include "SwapChain.h"

#include "Renderer.h"
#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>

namespace Gluten::Renderer {
	SwapChain::SceneData* SwapChain::s_SceneData = new SwapChain::SceneData;
	GraphicsContext* SwapChain::s_Context = nullptr;

	void SwapChain::BeginFrame(OrthographicCamera& camera)
	{
		switch (GlutenRenderer::GetAPI()) {
			case RendererAPI::None: GLUT_CORE_ERROR("RendererAPI::None is not currently supported!"); return;
			case RendererAPI::OpenGL:
				s_SceneData->ViewProjectionMatrix = camera.GetViewProjectionMatrix();
				break;
		}

	}

	void SwapChain::EndFrame()
	{

	}

	void SwapChain::Clear(glm::vec4 color)
	{
		switch (GlutenRenderer::GetAPI()) {
		case RendererAPI::None: GLUT_CORE_ERROR("RendererAPI::None is not currently supported!"); return;
		case RendererAPI::OpenGL:
			s_Context->Clear(color);
			break;
		}
	}

	void SwapChain::Submit(std::unique_ptr<Renderer::Shader>& shader, std::unique_ptr<Renderer::VertexArray>& vertexArray, std::unique_ptr<Renderer::Texture>& texture, glm::vec3 position, glm::vec3 rotation)
	{
		glm::mat4 transform = glm::translate(glm::mat4(1.0f), position);

		switch (GlutenRenderer::GetAPI()) {
		case RendererAPI::None: GLUT_CORE_ERROR("RendererAPI::None is not currently supported!"); return;
		case RendererAPI::OpenGL:
			shader->Bind();
			shader->UploadUniformMat4f(transform, "u_Transform");
			shader->UploadUniformMat4f(s_SceneData->ViewProjectionMatrix, "u_ViewProjection");
			texture->Bind();
			vertexArray->Bind();
			GLUT_CORE_INFO("Rendering Vertex Array with {0} Indices", vertexArray->GetIndexBuffer()->GetCount());
			glDrawElements(GL_TRIANGLES, vertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
			vertexArray->Unbind();
			shader->Unbind();
			break;
		}
	}
	
}