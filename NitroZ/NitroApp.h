#pragma once

#include "NitroZUtils.h"
#include "GameWindow.h"

#define FRAMES_PER_SECOND 30

namespace NitroZ
{
	class NITROZ_API NitroApp
	{
	public:
		void Run();
		virtual void OnUpdate();
		virtual void OnKeyPressed(KeyPressedEvent& event);
		int GetGameWindowWidth() const;
		int GetGameWindowHeight() const;
	protected:
		NitroApp();

	private:
		GameWindow mNitroZWindow;
		std::chrono::steady_clock::time_point mTimeOfNextFrame;
		std::chrono::milliseconds mFrameDuration{ 1000 / FRAMES_PER_SECOND};
	};
}
