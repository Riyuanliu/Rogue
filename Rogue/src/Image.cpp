#include "pch.h"
#include "Image.h"
#include "codeOpenGL/ImageOpenGL.h"
namespace Rogue 
{
	Image::Image(const std::string& filePath)
	{
#ifdef ROGUE_OPENGL
		mImplementation = std::unique_ptr<ImageImplement>{ new ImageOpenGL{filePath} };
#else 
		#only_openGL_is_supported_so_far
#endif
	}
	Image::Image(std::string&& filePath){
#ifdef ROGUE_OPENGL
		mImplementation = std::unique_ptr<ImageImplement>{ new ImageOpenGL{std::move(filePath)} };
#else 
		#only_openGL_is_supported_so_far
#endif
	}
	int Image::GetWidth() const
	{
		return mImplementation->GetWidth();
	}
	int Image::GetHeight() const
	{
		return mImplementation->GetHeight();
	}
	void Image::Bind()
	{
		mImplementation->Bind();
	}
}