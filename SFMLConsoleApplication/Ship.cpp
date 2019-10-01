#include "Ship.h"



Ship::Ship()
{
}

void Ship::update(float deltaTime)
{
	updatePosition(deltaTime);
	constrainPosition();
}

void Ship::updatePosition(float deltaTime)
{
	mSprite.move(deltaTime * mVelocity);
}

void Ship::constrainPosition()
{
	
}

Ship::~Ship()
{
}
