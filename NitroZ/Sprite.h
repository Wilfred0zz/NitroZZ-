#pragma once
namespace Nitroz 
{
	class Sprite
	{
	public:
		void LoadImage(const std::string& pictureFile);
		int GetWidth() const;
		int GetHeight() const;

	private:
		SpriteImplementation* mSpriteImplementation{ nullptr };
	};

}