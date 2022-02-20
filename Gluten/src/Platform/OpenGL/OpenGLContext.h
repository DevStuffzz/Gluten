#pragma once

#include "Gluten/Renderer/GraphicsContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>


class GLFWwindow;

namespace Gluten::Renderer {
	class OpenGLContext : public GraphicsContext {
	public:
		OpenGLContext(GLFWwindow* handle);

		virtual void Init() override;
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* m_WindowHandle;
	};
}