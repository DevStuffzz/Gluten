#include <Gluten.h>

class ExampleLayer : public Gluten::Layer {
public:
	ExampleLayer()
		: Layer("Example") 
	{
	}

	void OnUpdate() override {

		GLUT_CORE_INFO("ExampleLayer::Update");

		if (Gluten::Input::IsKeyPressed(KEY_TAB)) {
			GLUT_INFO("Tab was pressed");
		}
	}

	void OnEvent(Gluten::Event& event) override {
		GLUT_TRACE("{0}", event);
	}
};

class Sandbox : public Gluten::Application
{
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Gluten::ImGuiLayer());
	}

	~Sandbox() {

	}
};

Gluten::Application* Gluten::CreateApplication() {
	return new Sandbox();
}