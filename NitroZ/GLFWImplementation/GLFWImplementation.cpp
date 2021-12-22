#include "pch.h"
#include "GlFWImplementation.h"

namespace NitroZ {
	void GLFWImplementation::Init()
	{
		glfwInit();
	}
	void GLFWImplementation::CreateWindow(int width, int height, const std::string& name)
	{
		mWindow = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
		glfwMakeContextCurrent(mWindow);

		glfwSetWindowUserPointer(mWindow, &mCallbacks);


		glfwSetKeyCallback(mWindow, [](
			GLFWwindow* window, int key, int scancode, int action, int mods) {
				if (action == GLFW_PRESS || action == GLFW_REPEAT)
				{
					CallbackFunctions* callbacks{(CallbackFunctions *) glfwGetWindowUserPointer(window)};

					KeyPressedEvent event{ key };
					callbacks->KeyPressedCallback(event);
				}
			});
	}
	void GLFWImplementation::SwapBuffers()
	{
		glfwSwapBuffers(mWindow);
	}
	void GLFWImplementation::PollEvents()
	{
		glfwPollEvents();
	}
	int GLFWImplementation::GetWindowWidth() const
	{
		int width{ 0 };
		int height{ 0 };
		glfwGetWindowSize(mWindow, &width, &height);
		return width;
	}
	int GLFWImplementation::GetWindowHeight() const
	{
		int width{ 0 };
		int height{ 0 };
		glfwGetWindowSize(mWindow, &width, &height);
		return height;
	}
	void GLFWImplementation::SetKeyPressedCallback(std::function<void(KeyPressedEvent&)> func)
	{
		mCallbacks.KeyPressedCallback = func;
	}
}