#pragma once

#include "Utility.h"
#include "pch.h"
#include "ImageImplement.h"

namespace Rogue {
	class ROGUE_API Image {
	public:
		Image(const std::string& filePath);
		Image(std::string&& filePath);

		int GetWidth() const;
		int GetHeight() const;

		void Bind();

	private:
		std::unique_ptr<ImageImplement> mImplementation;

	};
}
