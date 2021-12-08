#pragma once
#include <pch.h>
#include "NitroZUtils.h"
#include "ShaderImplementation.h"

namespace NitroZ {
	class NITROZ_API Shader
	{
	public:
		Shader();
		void Load(const std::string& vertexFile, const std::string& fragmentFile);
		void SetVec2IntUniform(const std::string& unifName, int first, int second);
		void Use();
	private:
		std::unique_ptr<ShaderImplementation> mShader;
	};
}
