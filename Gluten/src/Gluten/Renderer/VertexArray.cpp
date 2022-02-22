#include "glutpch.h"
#include "VertexArray.h"

#include "Renderer.h"

#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Gluten::Renderer {

	VertexArray* VertexArray::Create()
	{
		switch (GlutenRenderer::GetAPI()) {
		case RendererAPI::None:
			GLUT_CORE_ASSERT(false, "RendererAPI::NONE is not supported");
			return nullptr;
		case RendererAPI::OpenGL:
			GLUT_CORE_INFO("Creating OpenGL Vertex Array");
			return new OpenGLVertexArray();
		}

		GLUT_CORE_ERROR("Unknown RendererAPI");
		return nullptr;
	}
}