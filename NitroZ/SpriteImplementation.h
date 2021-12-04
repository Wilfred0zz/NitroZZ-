#pragma once
#include"pch.h"

namespace NitroZ {
	class SpriteImplementation {
	public:
		virtual void LoadImage(const std::string& pictureFile);
		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;
		virtual void Bind() = 0;
	};
}