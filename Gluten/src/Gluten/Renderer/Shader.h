#pragma once

#include <string>

#include <glm/glm.hpp>

namespace Gluten::Renderer {
	class Shader {
	public:
		Shader(const std::string& vertexSrc, const std::string& fragSrc);
		~Shader();

		void Bind() const;
		void Unbind() const;

		void UploadUniform1f(float data, const char* name);
		void UploadUniform2f(glm::vec2 data, const char* name);
		void UploadUniform3f(glm::vec3 data, const char* name);
		void UploadUniform4f(glm::vec4 data, const char* name);
	private:
		uint32_t m_RendererID;
	};
}