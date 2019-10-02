#include "../SFML-2.5.1/include/SFML/Graphics.hpp"
#pragma once

using namespace sf;

class Ship
{
public:
	void update(float deltaTime);
	Ship(RenderWindow&, Texture& tex, Vector2f pos, float velocity, float radius);
	void draw();
	float getRadius();
	Vector2f getPosition();
	//~Ship();

private:

	void updatePosition(float deltaTime);
	void constrainPosition();
	void centerSprite();
	Sprite mSprite;
	float mVelocity;
	RenderWindow& mRenderWindow;
	float mRadius;
};

