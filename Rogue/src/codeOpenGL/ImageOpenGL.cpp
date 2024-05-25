#include "pch.h"
#include "glad/glad.h"
#include "stb_image.h"
#include "Utility.h"
#include "ImageOpenGL.h"

namespace Rogue {
	ImageOpenGL::ImageOpenGL(const std::string& filepath)
	{
		glGenTextures(1, &mTexture);
		glBindTexture(GL_TEXTURE_2D, mTexture);


		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(filepath.c_str(), &mWidth, &mHeight, &nrChannels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			
			ROGUE_ERROR(filepath<<"Failed to load a picture from file!!!");
		}

		stbi_image_free(data);
	}
	ImageOpenGL::ImageOpenGL(std::string&& filepath)
	{
		glGenTextures(1, &mTexture);
		glBindTexture(GL_TEXTURE_2D, mTexture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(filepath.c_str(), &mWidth, &mHeight, &nrChannels, 0);

		if (data) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else {

			ROGUE_ERROR(filepath<<"Failed to load texture" << std::endl);
		}
		stbi_image_free(data);
	}
	int ImageOpenGL::GetWidth() const
	{
		return mWidth;
	}
	int ImageOpenGL::GetHeight() const
	{
		return mHeight;
	}
	void ImageOpenGL::Bind() const
	{
		glBindTexture(GL_TEXTURE_2D, mTexture);
	}
	ImageOpenGL::~ImageOpenGL()
	{
		glDeleteTextures(1, &mTexture);
	}
}