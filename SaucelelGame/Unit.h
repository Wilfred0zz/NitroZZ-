#pragma once

#include "NitroZ.h"
class Unit
{
public:
	Unit() = delete;
	Unit(const std::string& imageFile, int xPos, int yPos, int speed);
	int GetUnitWidth() const;
	int GetUnitHeight() const;
	void SetPosX(int newX);
	void SetPosY(int newY);
	int GetPosX() const;
	int GetPosY() const;
	int GetSpeed() const;

	//CollideWith returns true is this unit and other unit collide( overlap )
	bool CollideWith(const Unit &other) const;

	void Draw(NitroZ::Shader & shader);

	enum class Direction {
		None,
		Up,
		Down,
		Left,
		Right
	};

	Unit::Direction GetDirection() const;
	void SetDirection(Unit::Direction newDirection);
	void UpdatePosition();

private:
	bool IsPositionPossible(int newX, int newY) const;
	NitroZ::Sprite mImage;
	int mPosX;
	int mPosY;
	int mSpeed;

	enum class Direction mDirection;
};

