#include "Coin.h"

Coin::Coin(RenderWindow& window, Texture& tex, Vector2f pos, Vector2f velocity, float radius) :
	mRenderWindow(window),
	mSprite(tex),
	mVelocity(velocity),
	mRadius(radius)
{
	centerSprite();
	mSprite.setPosition(pos);
}

void Coin::update(float deltaTime)
{
	mSprite.move(deltaTime * mVelocity);
}

Vector2f Coin::getPosition()
{
	return mSprite.getPosition();
}

void Coin::setPosition(Vector2f pos)
{
	mSprite.setPosition(pos);
}

void Coin::centerSprite()
{
	float originX = 0.5f * mSprite.getLocalBounds().width;
	float originY = 0.5f * mSprite.getLocalBounds().height;
	mSprite.setOrigin(originX, originY);
}

void Coin::draw()
{
	mRenderWindow.draw(mSprite);
}
