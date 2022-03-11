#pragma once
#include "Core.h"

#include "Gluten/Renderer/VertexArray.h"

namespace Gluten {
	class GLUT_API Primitives {
	public:
		static Gluten::Renderer::VertexArray* Square();
	private:
		Primitives();
	};
}