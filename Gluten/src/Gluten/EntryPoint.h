#pragma once


#ifdef GLUT_PLATFORM_WINDOWS

extern Gluten::Application* Gluten::CreateApplication();

int main(int argc, char** argv) {
	auto app = Gluten::CreateApplication();
	app->Run();
	delete app;
}

#endif // GLUT_PLATFORM_WINDOWS
