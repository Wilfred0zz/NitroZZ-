#pragma once

#include "NitroZUtils.h"
#include "WindowImplementation.h"
#include "pch.h"
#include "Events.h"
namespace NitroZ {
	class NITROZ_API GameWindow
	{
	public:
		GameWindow();
		void CreateWindow(int width, int height, const std::string & name);
		void SwapBuffers();
		void PollEvents();
		int GetWindowWidth() const;
		int GetWindowHeight() const;
		void SetKeyPressedCallback(std::function<void(KeyPressedEvent&)> func);


	private:
		std::unique_ptr<WindowImplementation> mWindow; //interface class which has the following methods from GameWindow.cpp
	};
}