#pragma once

#include "pch.h"
#include "../ShaderImplement.h"

namespace Rogue {
	class ShaderOpenGL : public ShaderImplement
	{
	public:
		ShaderOpenGL(const std::string& vertexFile, const std::string& fragmentFile);
		ShaderOpenGL(std::string&& vertexFile, std::string&& fragmentFile);
		~ShaderOpenGL();

		virtual void Bind() override;

		virtual void SetUniform2Ints(const std::string& uniformName, int val1, int val2) override;
		virtual void SetUniform2Ints(std::string&& uniformName, int val1, int val2) override;

	private:
		unsigned int mShaderProg{ 0 };
		std::string ReadFile(const std::string& filename);
		std::string ReadFile(std::string&& filename);


	};
}