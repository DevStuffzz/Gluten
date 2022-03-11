#pragma once

#include <string>

#include <glm/glm.hpp>

namespace Gluten::Renderer {
	class GLUT_API Shader {
	public:
		static inline Shader* DefaultShader() {
			std::string vertexSrc = R"(
				#version 330 core
			
				layout(location = 0) in vec3 a_Position;
				layout(location = 1) in vec4 a_Color;
				layout(location = 2) in vec2 a_TexCoords;

				uniform mat4 u_ViewProjection;
				uniform mat4 u_Transform;

				out vec2 v_TexCoords;

				void main()
				{
				
					v_TexCoords = a_TexCoords;
					//gl_Position = u_ViewProjection * vec4(a_Position, 1.0) * u_Transform;	
					gl_Position = vec4(a_Position, 1.0);	
				}
			)";

			std::string fragmentSrc = R"(
				#version 330 core
			
				uniform sampler2D u_Texture;
				uniform vec4 u_Color;
			
				in vec2 v_TexCoords;

				out vec4 color;

				void main()
				{
					//color = texture(u_Texture, v_TexCoords) * u_Color;
					color = vec4(1, 0, 0, 1);
				}
			)";

			return new Shader(vertexSrc, fragmentSrc);
		}
	public:
		Shader(const std::string& vertexSrc, const std::string& fragSrc);
		~Shader();

		void Bind() const;
		void Unbind() const;

		void UploadUniform1f(float data, const char* name);
		void UploadUniform2f(glm::vec2 data, const char* name);
		void UploadUniform3f(glm::vec3 data, const char* name);
		void UploadUniform4f(glm::vec4 data, const char* name);
		void UploadUniformMat4f(glm::mat4 data, const char* name);
	private:
		uint32_t m_RendererID;
	};
}