#include "../SFML-2.5.1/include/SFML/Graphics.hpp"
#include <vector>
#pragma once

using namespace sf;

class Asteroid
{
public:
	Asteroid(RenderWindow&, Texture&, Vector2f spawnPos, Vector2f velocity, float radius);
	~Asteroid();
	void update(float deltaTime);
	void setPosition(Vector2f pos);
	void draw();
	Vector2f getPosition();

private:
	void centerSprite();
	RenderWindow& mRenderWindow;
	Sprite mSprite;
	Vector2f mVelocity;
	float mRadius;
};

