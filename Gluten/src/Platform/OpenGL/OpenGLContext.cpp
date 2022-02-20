#include "glutpch.h"
#include "OpenGLContext.h"



namespace Gluten::Renderer {
	OpenGLContext::OpenGLContext(GLFWwindow* handle)
		: m_WindowHandle(handle)
	{
		GLUT_CORE_ASSERT(handle, "Window Handle is Null!")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		GLUT_CORE_ASSERT(status, "Failed to initialize Glad!");
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}