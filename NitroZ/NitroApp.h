#pragma once

#include "NitroZUtils.h"
#include "GameWindow.h"
namespace NitroZ
{
	class NITROZ_API NitroApp
	{
	public:
		void Run();
		virtual void OnUpdate();

	protected:
		NitroApp();

	private:
		GameWindow mNitroZWindow;

	};
}
