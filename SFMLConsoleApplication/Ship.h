#include "../SFML-2.5.1/include/SFML/Graphics.hpp"
#pragma once

using namespace sf;

class Ship
{
public:
	void update(float deltaTime);
	Ship(RenderWindow&, Texture& tex, Vector2f pos, float velocity, float radius);
	~Ship(); 
	void draw();
	float getRadius();
	Vector2f getPosition();
	//~Ship();

private:

	Vector2f input();
	void updatePosition(Vector2f input, float deltaTime);
	void constrainPosition(Vector2f& input);
	void centerSprite();
	Sprite mSprite;
	float mVelocity;
	RenderWindow& mRenderWindow;
	float mRadius;
};

