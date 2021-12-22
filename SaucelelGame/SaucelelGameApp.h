#pragma once
#include "NitroZ.h"
#include "Unit.h"
class SaucelelGameApp : public NitroZ::NitroApp
{
public:
	SaucelelGameApp();
	virtual void OnUpdate() override;
	virtual void OnKeyPressed(NitroZ::KeyPressedEvent& event) override;

private:
	Unit mHero;

	NitroZ::Shader mShader;
};