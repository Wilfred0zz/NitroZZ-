#include "pch.h"

#include "NitroApp.h"
#include "Sprite.h"
#include "Shader.h"

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


		//Shaders
		NitroZ::Shader myShader;
		myShader.Load("Assests/Shader/myVertexShaders.glsl",
			"Assests/Shader/myFragmentShader.glsl");

		//Texture
		NitroZ::Sprite fish;
		fish.LoadImage("Assests/Textures/Test.png");

		while (true) 
		{
			OnUpdate();

			glClearColor(0.0f, 0.0f, 0.5f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			fish.Bind();

			myShader.Use();
			glBindVertexArray(VAO);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

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