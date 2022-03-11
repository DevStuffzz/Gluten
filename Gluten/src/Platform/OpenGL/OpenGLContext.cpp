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

		glEnable(GL_DEPTH_TEST);
		glEnable(GL_MULTISAMPLE);

		GLUT_CORE_INFO("OpenGL Renderer: {0} {1}", glGetString(GL_VENDOR), glGetString(GL_RENDERER));
		GLUT_CORE_INFO("OpenGL Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
	void OpenGLContext::Clear(glm::vec4 color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
		glClear(GL_COLOR_BUFFER_BIT);
	}

}