#include "../SFML-2.5.1/include/SFML/Graphics.hpp"

#pragma once

using namespace sf;

class Ship
{
public:

	void update(float deltaTime);

	Ship();
	~Ship();
private:

	void updatePosition(float deltaTime);
	void constrainPosition();

	Sprite mSprite;
	Vector2f mVelocity;
};

