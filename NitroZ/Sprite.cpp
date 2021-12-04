#include "pch.h"
#include "Sprite.h"

namespace NitroZ 
{

	void Sprite::LoadImage(const std::string& pictureFile)
	{
		mSpriteImplementation->LoadImage(pictureFile);
	}

	int Sprite::GetWidth() const
	{
		return mSpriteImplementation->GetWidth();
	}

	int Sprite::GetHeight() const
	{
		return 0;
	}

}