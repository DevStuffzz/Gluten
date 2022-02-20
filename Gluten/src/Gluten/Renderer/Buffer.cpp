#include "glutpch.h"
#include "Buffer.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Gluten::Renderer {
	VertexBuffer* VertexBuffer::Create(float* data, uint32_t size)
	{
		switch (Renderer::GetAPI()) {
		case RendererAPI::None:
			GLUT_CORE_ASSERT(false, "RendererAPI::NONE is not supported");
			return nullptr;
		case RendererAPI::OpenGL:
			GLUT_CORE_INFO("Creating OpenGL VertexBuffer");
			return new OpenGLVertexBuffer(data, size);
		}

		GLUT_CORE_ERROR("Unknown RendererAPI");
		return nullptr;
	}
	IndexBuffer* IndexBuffer::Create(uint32_t* data, uint32_t size)
	{
		switch (Renderer::GetAPI()) {
		case RendererAPI::None:
			GLUT_CORE_ASSERT(false, "RendererAPI::NONE is not supported");
			return nullptr;
		case RendererAPI::OpenGL:
			GLUT_CORE_INFO("Creating OpenGL IndexBuffer");
			return new OpenGLIndexBuffer(data, size);
		}

		GLUT_CORE_ERROR("Unknown RendererAPI");
		return nullptr;
	}

}