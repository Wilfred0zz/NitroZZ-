#include "pch.h"

#include "NitroApp.h"
#include "Sprite.h"
#include "Shader.h"
#include "Renderer.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"

#include "stb_image.h"

namespace NitroZ
{
	void NitroApp::Run()
	{
		NITROZ_LOG("Nitroz app is running...");


		mNitroZWindow.CreateWindow(800, 600, "TEST");

		Renderer::Init();

		////Shaders
		NitroZ::Shader myShader;
		myShader.Load("Assets/Shader/myVertexShader.glsl",
			"Assets/Shader/myFragmentShader.glsl");
		////
		myShader.SetVec2IntUniform("screenSize",
			mNitroZWindow.GetWindowWidth(),
			mNitroZWindow.GetWindowHeight());

		//Texture
		NitroZ::Sprite fish;
		fish.LoadImage("Assets/Textures/Test.png");

		mTimeOfNextFrame = std::chrono::steady_clock::now() + mFrameDuration;


		while (true) 
		{

			Renderer::ClearFrame();
			OnUpdate();


			Renderer::Draw(fish, 100, 50, fish.GetWidth(), fish.GetHeight(), myShader);

			std::this_thread::sleep_until(mTimeOfNextFrame);

			mNitroZWindow.SwapBuffers();
			
			mNitroZWindow.PollEvents();

			mTimeOfNextFrame += mFrameDuration;
			
		}
		Renderer::ShutDown();
	}

	void NitroApp::OnUpdate() 
	{

	}
	NitroApp::NitroApp() {
		
	}
}