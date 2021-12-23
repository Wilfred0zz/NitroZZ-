#pragma once
#include "NitroZ.h"
#include "Unit.h"
#include <vector>
class SaucelelGameApp : public NitroZ::NitroApp
{
public:
	SaucelelGameApp();
	virtual void OnUpdate() override;
	virtual void OnKeyPressed(NitroZ::KeyPressedEvent& event) override;

private:
	Unit mHero;
	std::vector<Unit> mViruses;
	int mFrameCounter;
	NitroZ::Shader mShader;
};