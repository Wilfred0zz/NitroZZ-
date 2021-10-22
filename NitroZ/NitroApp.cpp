#include "pch.h"

#include "NitroApp.h"


namespace NitroZ
{
	void NitroApp::Run()
	{
		std::cout << "NitroZ is running..." << std::endl;
		while (true) 
		{
			OnUpdate();
		}
	}

	void NitroApp::OnUpdate() 
	{

	}
	NitroApp::NitroApp() {

	}
}