#include "pch.h"
#include "Renderer.h"
#include "OpenGLimpl/OpenGLRenderer.h"

namespace NitroZ
{
	Renderer::Renderer() {
#ifdef	NITROZ_OPENGL
		mImplementation = std::unique_ptr<RendererImplementation>(new OpenGLRenderer);
#else 
	#only_OpenGL_is_supported_so_far
#endif
	}

	void Renderer::Init()
	{
		if (mInstance == nullptr)
			mInstance = new Renderer;

	}

	void Renderer::Draw( Sprite& sprite,
		int xPos, int yPos,	//botom left corner of sprite
		int width, int height,
		 Shader& shader) {
		mImplementation->Draw(sprite, xPos, yPos, width, height, shader);
	}
	void Renderer::ClearFrame() {
		mImplementation->ClearFrame();
	}

	void Renderer::ShutDown()
	{
		if (mInstance != nullptr) {
			delete mInstance;
			mInstance = nullptr;
		}
	}
}