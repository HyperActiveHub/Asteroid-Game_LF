#include "../SFML-2.5.1/include/SFML/Graphics.hpp"
#include <vector>

#pragma once

using namespace sf;

class Asteroid
{
public:
	Asteroid(RenderWindow&, Texture, Vector2f spawnPos, Vector2f velocity, float radius);

	void update(float deltaTime);
	Vector2f getPosition();

private:

	Sprite mSprite;
	Vector2f mVelocity;
};

