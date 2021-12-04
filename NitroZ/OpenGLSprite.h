#pragma once

#include "pch.h"
#include "NitroZUtils.h"

namespace NitroZ {

	class NITROZ_API OpenGLSprite
	{
	public:
		OpenGLSprite();
		OpenGLSprite(const std::string& pictureFile);
		~OpenGLSprite();

		void LoadImage(const std::string& pictureFile);
		unsigned char* GetDataPointer() const;
		int GetWidth() const;
		int GetHeight() const;

	private:
		unsigned char* mImage{ nullptr };
		int mWidth{ 0 };
		int mHeight{ 0 };

	};

}
