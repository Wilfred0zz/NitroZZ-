#pragma once

#include "pch.h"
#include "NitroZUtils.h"
#include "SpriteImplementation.h"
#include "glad/glad.h"

namespace NitroZ {

	class OpenGLSprite: public SpriteImplementation
	{
	public:
		OpenGLSprite();
		OpenGLSprite(const std::string& pictureFile);
		~OpenGLSprite();

		virtual void LoadImage(const std::string& pictureFile)  override;
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;
		virtual void Bind() override;

	private:
		unsigned int mTexture{ 0 };
		unsigned char* mImage{ nullptr };
		int mWidth{ 0 };
		int mHeight{ 0 };

	};

}
