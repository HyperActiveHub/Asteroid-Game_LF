#include "Ship.h"



Ship::Ship(RenderWindow& window, Texture& tex, Vector2f pos, float velocity, float radius) :
	mRenderWindow(window),
	mSprite(tex),
	mVelocity(velocity),
	mRadius(radius)
{
	centerSprite();
	mSprite.setPosition(pos);
}

void Ship::update(float deltaTime)
{
	updatePosition(deltaTime);
	constrainPosition();
}

void Ship::updatePosition(float deltaTime)
{
	Vector2f input;
	if (Keyboard::isKeyPressed(Keyboard::Key::W))
	{
		input.y = -1;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::S))
	{
		input.y = 1;
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::D))
	{
		input.x = 1;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::A))
	{
		input.x = -1;
	}

	mSprite.move(deltaTime * mVelocity * input);
}

void Ship::constrainPosition()
{

}

void Ship::draw()
{
	mRenderWindow.draw(mSprite);
}

void Ship::centerSprite()
{
	float y = mSprite.getLocalBounds().height * 0.5f;
	float x = mSprite.getLocalBounds().width * 0.5f;
	mSprite.setOrigin(x, y);
}

Vector2f Ship::getPosition()
{
	return mSprite.getPosition();
}
