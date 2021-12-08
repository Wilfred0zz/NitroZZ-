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
}