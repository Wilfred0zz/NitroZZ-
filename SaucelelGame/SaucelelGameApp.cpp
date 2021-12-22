#include "SaucelelGameApp.h""

SaucelelGameApp::SaucelelGameApp(): mHero("Assets/Textures/Hero.png",0,0,10)
{
	mShader.Load("Assets/Shader/myVertexShader.glsl", "Assets/Shader/myFragmentShader.glsl");
	mShader.SetVec2IntUniform("screenSize", 1280, 800);
}

void SaucelelGameApp::OnUpdate()
{
	mHero.UpdatePosition();
	mHero.Draw(mShader);
}

void SaucelelGameApp::OnKeyPressed(NitroZ::KeyPressedEvent& event)
{
	switch (event.GetKeyCode()) 
	{
	case NITROZ_KEY_LEFT:
		//mHero.SetPosX(mHero.GetPosX() - mHero.GetSpeed());
		mHero.SetDirection(Unit::Direction::Left);
		break;
	case NITROZ_KEY_RIGHT:
		//mHero.SetPosX(mHero.GetPosX() + mHero.GetSpeed());
		mHero.SetDirection(Unit::Direction::Right);
		break;
	case NITROZ_KEY_DOWN:
		//mHero.SetPosY(mHero.GetPosY() - mHero.GetSpeed());
		mHero.SetDirection(Unit::Direction::Down);
		break;
	case NITROZ_KEY_UP:
		//mHero.SetPosY(mHero.GetPosY() + mHero.GetSpeed());
		mHero.SetDirection(Unit::Direction::Up);
		break;
	}
}
