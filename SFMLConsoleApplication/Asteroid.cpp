#include "Asteroid.h"

using namespace sf;

Asteroid::Asteroid(RenderWindow& window, Texture& tex, Vector2f spawnPos, Vector2f velocity, float radius) :
	mRenderWindow(window),
	mSprite(tex),
	mVelocity(velocity),
	mRadius(radius)
{
	centerSprite();
	mSprite.setPosition(spawnPos);
}

void Asteroid::update(float deltaTime)
{
	mSprite.move(deltaTime * mVelocity);
}

void Asteroid::draw()
{
	mRenderWindow.draw(mSprite);
}

void Asteroid::centerSprite()
{
	float offsetX = mSprite.getLocalBounds().width * 0.5f;
	float offsetY = mSprite.getLocalBounds().height * 0.5f;
	mSprite.setOrigin(offsetX, offsetY);
}

Vector2f Asteroid::getPosition()
{
	return mSprite.getPosition();
}

void Asteroid::setPosition(Vector2f pos)
{
	mSprite.setPosition(pos);
}