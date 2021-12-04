#include "pch.h"

#include "NitroApp.h"
#include "Sprite.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include "stb_image.h"

namespace NitroZ
{
	void NitroApp::Run()
	{
		std::cout << "NitroZ is running..." << std::endl;

		mNitroZWindow.CreateWindow(1100, 800, "TEST");

		NitroZ::Sprite fish;
		fish.LoadImage("Assests / Textures / Test.png");

		while (true) 
		{
			OnUpdate();

			fish.Bind();

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