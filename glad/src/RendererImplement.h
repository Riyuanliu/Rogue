#pragma once

#include "codeOpenGL/RendererOpenGL.h"
#include "Image.h"
#include "Shader.h"

namespace Rogue {
	class RendererImplement {
	public:
		virtual void Draw(Image& pic, int x, int y) = 0
		virtual void Draw(Image& pic, Shader& shader, int x, int y) = 0
		virtual ~RendererImplement() {};
	};
	
}