#pragma once

#include "Shader.h"
#include "VertexArray.h"
#include "Camera.h"
#include "Texture.h"
#include "GraphicsContext.h"

namespace Gluten::Renderer {

	class GLUT_API SwapChain {
	public:
		static inline void SetContext(GraphicsContext* context) { s_Context = context; }
		static inline GraphicsContext* GetContext() { return s_Context; };
	public:
		static void BeginFrame(OrthographicCamera& Camera);
		static void EndFrame();


		static void Clear(glm::vec4 color);

		static void Submit(std::unique_ptr<Renderer::Shader>& shader, std::unique_ptr<Renderer::VertexArray>& vertexArray, std::unique_ptr<Renderer::Texture>& texture, glm::vec3 position, glm::vec3 rotation);
	private:
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};

		static GraphicsContext* s_Context;
		static SceneData* s_SceneData;
	};
}