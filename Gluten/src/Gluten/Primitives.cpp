#include "glutpch.h"
#include "Primitives.h"

namespace Gluten {

    Gluten::Renderer::VertexArray* Primitives::Square()
    {
		Renderer::VertexArray* vao = Renderer::VertexArray::Create();
		vao->Bind();
		float vertices[] = {
			// positions          // colors			  // texture coords
			 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f, 1.0f,   1.0f, 1.0f, // top right
			 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f, 1.0f,   1.0f, 0.0f, // bottom right
			-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f, 1.0f,   0.0f, 0.0f, // bottom left
			-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f, 1.0f,   0.0f, 1.0f  // top left 
		};

		std::shared_ptr<Gluten::Renderer::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Gluten::Renderer::VertexBuffer::Create(vertices, sizeof(vertices)));
		Gluten::Renderer::BufferLayout layout = {
			{ Gluten::Renderer::ShaderDataType::Float3, "a_Position" },
			{ Gluten::Renderer::ShaderDataType::Float4, "a_Color" },
			{ Gluten::Renderer::ShaderDataType::Float2, "a_TexCoord" },
		};
		vertexBuffer->SetLayout(layout);
		vao->AddVertexBuffer(vertexBuffer);

		uint32_t indices[] = {
			0, 1, 3, // first triangle
		    1, 2, 3  // second triangle
		};


		std::shared_ptr<Gluten::Renderer::IndexBuffer> indexBuffer;
		indexBuffer.reset(Gluten::Renderer::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		vao->AddIndexBuffer(indexBuffer);

		return vao;
	}

}