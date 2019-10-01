#include "Asteroid.h"

using namespace sf;

Asteroid::Asteroid(RenderWindow& window, Texture tex, Vector2f spawnPos, Vector2f velocity, float radius)
{
	//RenderWindow must be pointer/adress of?
}

void Asteroid::update(float deltaTime)
{
	mSprite.move(deltaTime * mVelocity);
}

Vector2f Asteroid::getPosition()
{
	return mSprite.getPosition();
}
