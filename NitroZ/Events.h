#pragma once
#include "NitroZUtils.h"

namespace NitroZ {

	class KeyPressedEvent {
	public:
		KeyPressedEvent(int keyCode);
		int GetKeyCode() const;
	private:
		int mKeyCode{ -1 };
	};
		
}