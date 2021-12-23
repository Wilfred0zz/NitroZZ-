#include "SaucelelGameApp.h"

SaucelelGameApp::SaucelelGameApp() : mHero("Assets/Textures/Hero.png", 0, 0, 10), mFrameCounter(0)
{
	mShader.Load("Assets/Shader/myVertexShader.glsl", "Assets/Shader/myFragmentShader.glsl");
	mShader.SetVec2IntUniform("screenSize", 800, 800);
}

void SaucelelGameApp::OnUpdate()
{
	mHero.UpdatePosition();

	//update existing viruses
	for (auto& virus : mViruses)
	{
		virus.UpdatePosition();
	}
	////introduce new virus every second
	if (mFrameCounter % FRAMES_PER_SECOND == 0 && mViruses.size()<10)
	{
		int newX{ rand() % 700 };
		int newY{ rand() % 700 };

		Unit::Direction newDir;
		int dirVal{ rand() % 4};
		if (dirVal == 0)
			newDir = Unit::Direction::Down;
		else if (dirVal == 1)
			newDir = Unit::Direction::Up;
		else if (dirVal == 2)
			newDir = Unit::Direction::Left;
		else 
			newDir = Unit::Direction::Right;

		mViruses.push_back(Unit{ "Assets/Textures/Virus.png", newX, newY, 10 });
		mViruses.back().SetDirection(newDir);

	}
	//check collitions
	auto it = mViruses.begin();
	while(it != mViruses.end()) {
		if (mHero.CollideWith(*it))
		{
			it = mViruses.erase(it);
		}
		else {
			it++;
		}
	}

	for (auto& virus : mViruses) {
		virus.Draw(mShader);
	}
	mHero.Draw(mShader);
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
