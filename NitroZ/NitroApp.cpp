#include "pch.h"

#include "NitroApp.h"

#include "GLFW/glfw3.h"

namespace NitroZ
{
	void NitroApp::Run()
	{
		std::cout << "NitroZ is running..." << std::endl;

		mNitroZWindow.CreateWindow(1100, 800, "TEST");

		while (true) 
		{
			OnUpdate();
			mNitroZWindow.SwapBuffers();
			
			mNitroZWindow.PollEvents();
			
		}
	}

	void NitroApp::OnUpdate() 
	{

	}
	NitroApp::NitroApp() {
		
	}
}