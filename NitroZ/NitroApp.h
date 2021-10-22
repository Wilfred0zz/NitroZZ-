#pragma once

#include "NitroZUtils.h"

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

	};
}
