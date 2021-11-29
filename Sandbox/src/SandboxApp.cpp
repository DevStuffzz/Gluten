#include <Gluten.h>

class Sandbox : public Gluten::Application
{
public:
	Sandbox() {
	}

	~Sandbox() {

	}
};

Gluten::Application* Gluten::CreateApplication() {
	return new Sandbox();
}