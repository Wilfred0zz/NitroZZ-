#include "Unit.h"

Unit::Unit(const std::string& imageFile, int xPos, int yPos, int speed): mPosX(xPos), mPosY(yPos), mSpeed(speed), mDirection(Direction::None)
{
    mImage.LoadImage(imageFile);
}

int Unit::GetUnitWidth() const
{
    return mImage.GetWidth();
}

int Unit::GetUnitHeight() const
{
    return mImage.GetHeight();
}

void Unit::SetPosX(int newX)
{
    mPosX = newX;
}

void Unit::SetPosY(int newY)
{
    mPosY = newY;
}

int Unit::GetPosX() const
{
    return mPosX;
}

int Unit::GetPosY() const
{
    return mPosY;
}

int Unit::GetSpeed() const
{
    return mSpeed;
}

bool Unit::CollideWidth(const Unit& other) const
{
    int oXleft{ other.GetPosX() };
    int oXright{ other.GetPosX() + other.GetUnitWidth() };
    int oYbottom{ other.GetPosY() };
    int oYtop{ other.GetPosY() + other.GetUnitHeight() };

    bool intersectOnX{
        (mPosX <= oXleft && oXleft <= mPosX + GetUnitWidth()) ||
        (mPosX <= oXright && oXright <= mPosX + GetUnitWidth())
    };

    bool intersectOnY{
         (mPosY<=oYbottom && oYbottom<= mPosY+GetUnitHeight()) ||
         (mPosY <= oYtop && oYtop <= mPosY + GetUnitHeight())
    };

    return intersectOnX && intersectOnY;
}

void Unit::Draw(NitroZ::Shader& shader)
{
    NitroZ::Renderer::Draw(mImage, mPosX, mPosY, mImage.GetWidth(), mImage.GetHeight(), shader);
}

Unit::Direction Unit::GetDirection() const
{
    return mDirection;
}

void Unit::SetDirection(Unit::Direction newDirection)
{
    mDirection = newDirection;
}

void Unit::UpdatePosition()
{
    switch (mDirection) {
    case Direction::Down:
         mPosY -= mSpeed;
         break;
    case Direction::Up:
         mPosY += mSpeed;
         break;
    case Direction::Left:
        mPosX -= mSpeed;
        break;
    case Direction::Right:
        mPosX += mSpeed;
        break;
    }
}
