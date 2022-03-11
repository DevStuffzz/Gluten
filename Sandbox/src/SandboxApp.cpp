#include <Gluten.h>

class ExampleLayer : public Gluten::Layer {
public:
	ExampleLayer()
		: Layer("Example"),
		m_Camera(Gluten::Renderer::OrthographicCamera(-1.6f, 1.6f, -0.9f, 0.9f)),
		m_DvDPosition(0.0f),
		m_CameraPosition(0.0f, 0.0f, 1.0f),
		m_DvDScale(1.0f)
	{ 
		m_Camera.SetPosition(m_CameraPosition);
		m_DefaultShader.reset(Gluten::Renderer::Shader::DefaultShader());
		m_DvDTexture.reset(new Gluten::Renderer::Texture("Textures\\DVD.png"));
		m_SquareVA.reset(Gluten::Primitives::Square());
	}

	void OnUpdate() override {

		Gluten::Renderer::SwapChain::Clear({ 0.1f, 0.1f, 0.1f, 1.0f });

		Gluten::Renderer::SwapChain::BeginFrame(m_Camera);

		m_DefaultShader->UploadUniform4f({ 1.0f, 1.0f, 1.0f, 1.0f }, "u_Color");
		Gluten::Renderer::SwapChain::Submit(m_DefaultShader, m_SquareVA, m_DvDTexture, m_DvDPosition, m_DvDScale);

		Gluten::Renderer::SwapChain::EndFrame();
	}

	void OnEvent(Gluten::Event& event) override {
		if (Gluten::Input::IsKeyPressed(KEY_ESCAPE)) Gluten::Application::Quit();
	}
private:
	std::unique_ptr<Gluten::Renderer::Shader> m_DefaultShader;
	std::unique_ptr<Gluten::Renderer::Texture> m_DvDTexture;
	std::unique_ptr<Gluten::Renderer::VertexArray> m_SquareVA;
	
	Gluten::Renderer::OrthographicCamera m_Camera;

	glm::vec3 m_DvDPosition;
	glm::vec3 m_DvDScale;
	glm::vec3 m_CameraPosition;

	
};

class Sandbox : public Gluten::Application
{
public:
	Sandbox() {
		PushLayer(new Gluten::ImGuiLayer());
		PushLayer(new ExampleLayer());
	}

	~Sandbox() {

	}
};

Gluten::Application* Gluten::CreateApplication() {
	return new Sandbox();
}