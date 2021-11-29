#pragma once


#ifdef GLUT_PLATFORM_WINDOWS

extern Gluten::Application* Gluten::CreateApplication();

int main(int argc, char** argv) {
	Gluten::Log::Init();
	GLUT_CORE_WARN("Initialized API Logger");
	GLUT_INFO("Initialized Client Logger");
	auto app = Gluten::CreateApplication();
	app->Run();
	delete app;
}

#endif // GLUT_PLATFORM_WINDOWS