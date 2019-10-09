#include "../SFML-2.5.1/include/SFML/Graphics.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Asteroid.h"
#include "Coin.h"
#include "Ship.h"
#pragma once

using namespace sf;

typedef std::vector<Asteroid*> AsteroidVector;

class Game
{
public:
	Game();
	void run();

private:
	RenderWindow mRenderWindow;
	Texture mShipTexture, mCoinTexture, mAsteroidTexture;
	AsteroidVector mAsteroids;
	float mSpawnTime;
	bool mGameOver, mQuit;
	Ship* mShip;
	Coin* mCoin;
	Ship* createShip();
	Coin* createCoin();
	Font mFont;
	Text mPauseText, mGoText, mRestartText;
	Texture loadTexture(std::string fileName);
	Font loadFont(std::string fileName);
	Vector2f getRandomSpawnPosition(float radius);
	Vector2f getRandomAsteroidVelocity();
	bool overlap(Ship*, Coin*);
	bool overlap(Ship* ship, AsteroidVector asteroids);
	void restartGame();
	void resetCoin();
	void handleWindowEvents();
	void clearWindow();
	void updateShip(float deltaTime);
	void updateCoin(float deltaTime);
	void updateAsteroids(float deltaTime);
	void createAsteroids(float deltaTime);
	//void destroyObject();
	void destroyGameobjects();
	void resetAsteroid(Asteroid*);
	void handleCoinPickup();
	void handleLostCoin();
	void handleAsteroidCollisions();
	void drawShip();
	void drawCoin();
	void drawAsteroids();
	void displayWindow();
	void initilizeRandomizer();
	void setFramerateLimit();
	void textInit();
	void editText(Text& textMember, std::string newText, Vector2f, Color, unsigned int);

	template<class T> void destroyObject(T&);
};

