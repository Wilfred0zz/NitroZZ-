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



		mTimeOfNextFrame = std::chrono::steady_clock::now() + mFrameDuration;


		while (true) 
		{

			Renderer::ClearFrame();
			OnUpdate();


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
	void NitroApp::OnKeyPressed(KeyPressedEvent& event)
	{
		NITROZ_LOG(event.GetKeyCode());
	}
	int NitroApp::GetGameWindowWidth() const
	{
		return mNitroZWindow.GetWindowWidth();
	}
	int NitroApp::GetGameWindowHeight() const
	{
		return mNitroZWindow.GetWindowHeight();
	}
	NitroApp::NitroApp() {
		mNitroZWindow.CreateWindow(800, 800, "SaverGame");

		mNitroZWindow.SetKeyPressedCallback([this](KeyPressedEvent& event) {
			OnKeyPressed(event);
			});

		Renderer::Init();
	}
}