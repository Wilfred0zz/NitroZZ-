#include "pch.h"
#include "GameWindow.h"
#include "GLFWImplementation/GlFWImplementation.h"

namespace NitroZ {
	GameWindow::GameWindow() 
	{
#ifdef NITROZ_WINDOWS
		mWindow = new GLFWImplementation();
#elif NITROZ_MAC
		mWindow = new GLFWImplementation();
#elif NITROZ_LINUX
		mWindow = new GLFWImplementation();
#else 
		#only_Windows_Linux_Mac_are_supported
#endif

		mWindow->Init();
	}

	void GameWindow::CreateWindow(int width, int height, const std::string & name)
	{
		mWindow->CreateWindow(width, height, name);
	}

	void GameWindow::SwapBuffers()
	{
		mWindow->SwapBuffers();
	}

	void GameWindow::PollEvents()
	{
		mWindow->PollEvents();
	}

	int GameWindow::GetWindowWidth() const
	{
		return mWindow->GetWindowWidth();
	}

	int GameWindow::GetWindowHeight() const
	{
		return mWindow->GetWindowHeight();
	}

}