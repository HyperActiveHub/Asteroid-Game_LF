#include "../SFML-2.5.1/include/SFML/Graphics.hpp"
#pragma once

using namespace sf;


class Coin
{
public:
	Coin(RenderWindow&, Texture& tex, Vector2f pos, Vector2f velocity, float radius);
	void update(float deltaTime);
	void draw();
	Vector2f getPosition();
	void setPosition(Vector2f pos);
	float getRadius();
	//~Coin();
private:
	void centerSprite();
	RenderWindow& mRenderWindow;
	Sprite mSprite;
	Vector2f mVelocity;
	float mRadius;
};

