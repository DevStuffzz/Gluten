#pragma once


#include "Gluten/Core.h"

#include "stb_image.h"

namespace Gluten::Renderer {
	class GLUT_API Texture {
	public:
		Texture(const char* location);

		void Bind();
		void Unbind();

		inline uint32_t GetID() const { return m_RendererID; }
	private:
		const char* m_Location;
		
		uint32_t m_Format;

		uint32_t m_RendererID;
	};
}