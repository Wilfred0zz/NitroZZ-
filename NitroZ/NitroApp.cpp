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
		std::cout << "NitroZ is running..." << std::endl;

		mNitroZWindow.CreateWindow(1100, 800, "TEST");
		Renderer::Init();

		////Shaders
		NitroZ::Shader myShader;
		myShader.Load("/Assets/Shader/myVertexShader.glsl",
			"/Assets/Shader/myFragmentShader.glsl");
		////
		myShader.SetVec2IntUniform("screenSize",
			mNitroZWindow.GetWindowWidth(),
			mNitroZWindow.GetWindowHeight());

		//Texture
		NitroZ::Sprite fish;
		fish.LoadImage("/Assets/Textures/Test.png");

		while (true) 
		{

			Renderer::ClearFrame();
			OnUpdate();


			Renderer::Draw(fish, 100, 50, fish.GetWidth(), fish.GetHeight(), myShader);

			mNitroZWindow.SwapBuffers();
			
			mNitroZWindow.PollEvents();

			
			
		}
		Renderer::ShutDown();
	}

	void NitroApp::OnUpdate() 
	{

	}
	NitroApp::NitroApp() {
		
	}
}