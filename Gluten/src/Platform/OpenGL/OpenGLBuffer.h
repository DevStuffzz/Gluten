#pragma once

#include "Gluten/Renderer/Buffer.h"

namespace Gluten::Renderer {
	class OpenGLVertexBuffer : public VertexBuffer {
	public:
		OpenGLVertexBuffer(float* data, uint32_t size);
		virtual ~OpenGLVertexBuffer();

		virtual void Bind() const;
		virtual void Unbind() const;
	private:
		uint32_t m_RendererID;
	};

	class OpenGLIndexBuffer : public IndexBuffer {
	public:
		OpenGLIndexBuffer(uint32_t* data, uint32_t count);
		virtual ~OpenGLIndexBuffer();

		virtual void Bind() const;
		virtual void Unbind() const;

		virtual uint32_t GetCount() const { return m_Count; }

	private:
		uint32_t m_RendererID;
		uint32_t m_Count;
	};
}