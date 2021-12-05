#include "pch.h"
#include "Shader.h"
#include "OpenGLimpl/OpenGLShader.h"

namespace NitroZ {
	Shader::Shader()
	{
#ifdef NITROZ_OPENGL
		mShader = std::unique_ptr<ShaderImplementation>{ new OpenGLShader };
#else
		#only_OpenGL_is_implemented_at_the_moment

#endif

	}

	void Shader::Load(const std::string& vertexFile, const std::string& fragmentFile)
	{
		mShader->Load(vertexFile, fragmentFile);
	}

	void Shader::Use()
	{
		mShader->Use();
	}
}