#include "glutpch.h"
#include "Renderer.h"

#include "Platform/OpenGL/OpenGLContext.h"
#include "Gluten/Application.h"
#include <GLFW/glfw3.h>

namespace Gluten::Renderer {
#ifdef GLUT_PLATFORM_WINDOWS
#ifndef GLUT_RENDERER_IMPL
#define GLUT_RENDERER_IMPL
	RendererAPI GlutenRenderer::s_RendererAPI = RendererAPI::OpenGL;
#endif
#endif
}
