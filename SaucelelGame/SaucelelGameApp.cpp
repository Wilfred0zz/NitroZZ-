#include "SaucelelGameApp.h"

SaucelelGameApp::SaucelelGameApp() : mHero("Assets/Textures/Hero.png", 0, 0, 10), mFrameCounter(0), mBackground("Assets/Textures/Background.png", 0,0,0 )
{
	mShader.Load("Assets/Shader/myVertexShader.glsl", "Assets/Shader/myFragmentShader.glsl");
	mShader.SetVec2IntUniform("screenSize", 800, 800);
}

void SaucelelGameApp::OnUpdate()
{
	mHero.UpdatePosition();
	mBackground.Draw(mShader);

	int regularVirusSize = 0;
	//update existing viruses
	for (auto& virus : mViruses)
	{
		virus.UpdatePosition();
	}
	for (auto& Redvirus : mRedVirus)
	{
		Redvirus.UpdatePosition();
	}
	////introduce new virus every second
	if (mFrameCounter % FRAMES_PER_SECOND == 0 && mViruses.size()<25)
	{
		int newX{ rand()% 790 };
		int newY{ 780 };

		Unit::Direction newDir;
		int dirVal{ rand() % 1};
		if (dirVal == 0)
			newDir = Unit::Direction::Down;
		else 
			newDir = Unit::Direction::Up;
		if (mFrameCounter > 20) {
			mRedVirus.push_back(Unit{ "Assets/Textures/RedVirus.png", newX+35, newY-90,  12 });
			mRedVirus.back().SetDirection(newDir);
		}
		mViruses.push_back(Unit{ "Assets/Textures/Virus.png", newX, newY, 18 });
		mViruses.back().SetDirection(newDir);

	}
	//check collitions
	auto it = mViruses.begin();
	while(it != mViruses.end()) {
		if (mHero.CollideWith(*it))
		{
			regularVirusSize++;
			it = mViruses.erase(it);
			//HeroSpeed = HeroSpeed - 1;
			isAlive = true;
		}
		else {
			it++;
		}
	}
	auto itr = mRedVirus.begin();
	while (itr != mRedVirus.end()) {
		if (mHero.CollideWith(*itr))
		{
			itr = mRedVirus.erase(itr);
			//HeroSpeed = HeroSpeed - 2;
			isAlive = false;
		}
		else {
			itr++;
		}
	}

	for (auto& virus : mViruses) {
		virus.Draw(mShader);
	}
	for (auto& Redvirus : mRedVirus) {
		Redvirus.Draw(mShader);
	}

	if (isAlive) {
		mHero.Draw(mShader);
	}
	mFrameCounter++;
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
