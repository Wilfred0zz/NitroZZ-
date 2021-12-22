#include "pch.h"
#include "Events.h"


namespace NitroZ {
	KeyPressedEvent::KeyPressedEvent(int keyCode) :mKeyCode(keyCode)
	{
	}

	int KeyPressedEvent::GetKeyCode() const
	{
		return mKeyCode;
	}
}