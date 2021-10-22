#include "pch.h"

#include "NitroApp.h"

#include "GLFW/glfw3.h"

namespace NitroZ
{
	void NitroApp::Run()
	{
		std::cout << "NitroZ is running..." << std::endl;

		GLFWwindow* window;

		glfwInit();
		window = glfwCreateWindow(800, 600, "Test", NULL, NULL);

		while (true) 
		{
			OnUpdate();

			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}

	void NitroApp::OnUpdate() 
	{

	}
	NitroApp::NitroApp() {

	}
}