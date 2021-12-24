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
	int HeroSpeed = 15;
	bool isAlive = true;

private:
	Unit mHero;
	std::vector<Unit> mViruses;
	std::vector<Unit> mRedVirus;
	Unit mBackground;
	int mFrameCounter;
	NitroZ::Shader mShader;

};