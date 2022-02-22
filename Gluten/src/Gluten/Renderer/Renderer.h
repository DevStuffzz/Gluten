#pragma once



namespace Gluten::Renderer {
	enum class RendererAPI {
		None = 0, OpenGL = 1
	};

	class GlutenRenderer {
	public:
		inline static RendererAPI GetAPI() { return s_RendererAPI; };
	private:
		static RendererAPI s_RendererAPI;
	};
}