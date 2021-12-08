#pragma once
#include "RendererImplementation.h"
#include "Shader.h"
#include "Sprite.h"


namespace NitroZ {
	
	class OpenGLRenderer : public RendererImplementation
	{
	public:
		OpenGLRenderer();
		virtual void Draw( Sprite& sprite,
			int xPos, int yPos,	//botom left corner of sprite
			int width, int height,
			Shader& shader) override;
		virtual void ClearFrame() override;

	};
}