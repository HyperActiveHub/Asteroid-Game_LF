#include "Ship.h"
#include <iostream>


Ship::Ship(RenderWindow& window, Texture& tex, Vector2f pos, float velocity, float radius) :
	mRenderWindow(window),
	mSprite(tex),
	mVelocity(velocity),
	mRadius(radius)
{
	centerSprite();
	mSprite.setPosition(pos);
}

Ship::~Ship()
{
	std::cout << "Ship cleared from memory" << std::endl;
}

void Ship::update(float deltaTime)
{
	Vector2f direction = input();
	constrainPosition(direction);
	updatePosition(direction, deltaTime);
}

Vector2f Ship::input()
{
	Vector2f input;
	if (Keyboard::isKeyPressed(Keyboard::Key::W) || Keyboard::isKeyPressed(Keyboard::Key::Up))
	{
		input.y = -1;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::S) || Keyboard::isKeyPressed(Keyboard::Key::Down))
	{
		input.y = 1;
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::D) || Keyboard::isKeyPressed(Keyboard::Key::Right))
	{
		input.x = 1;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::A) || Keyboard::isKeyPressed(Keyboard::Key::Left))
	{
		input.x = -1;
	}
	return input;
}

void Ship::constrainPosition(Vector2f& input)
{
	if (input.x > 0 && getPosition().x > mRenderWindow.getSize().x - mRadius)
	{
		input.x = 0;
	}
	else if (input.x < 0 && getPosition().x < mRadius)
	{
		input.x = 0;
	}
	if (input.y > 0 && getPosition().y > mRenderWindow.getSize().y - mRadius)
	{
		input.y = 0;
	}
	else if (input.y < 0 && getPosition().y < mRadius)
	{
		input.y = 0;
	}
}

void Ship::updatePosition(Vector2f input, float deltaTime)
{
	mSprite.move(deltaTime * mVelocity * input);
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
