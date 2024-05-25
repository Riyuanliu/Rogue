#pragma once

#include "pch.h"
#include "../ImageImplement.h"


namespace Rogue {
	class ImageOpenGL : public ImageImplement {
	public:
		ImageOpenGL(const std::string& filepath);
		ImageOpenGL(std::string&& filepath);
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;
		virtual void Bind() const override;

		~ImageOpenGL();

	private:
		unsigned int mTexture{ 0 };
		int mWidth{ 0 };
		int mHeight{ 0 };
	};
}