#include "Game.h"
#include <string>
using namespace sf;
using namespace std;

namespace
{
	const string windowTitle = "Asteroids";
	const VideoMode videoMode = VideoMode(768, 1024);
	const Color backgroundColor = Color::Black;
	const int FRAMERATE_LIMIT = 144;

	const float SHIP_RADIUS = 20.0f;
	const float SHIP_VELOCITY = 400.0f;

	const float COIN_RADIUS = 16.0f;
	const float COIN_VELOCITY = 80.0f;

	const float ASTEROID_RADIUS = 32.0f;
	const float ASTEROID_SPAWN_DELTA = 2.0f;
	const float ASTEROID_MIN_VELOCITY = 80.0f;
	const float ASTEROID_DELTA_VELOCITY = 200.0f;
}

Game::Game() :
	mRenderWindow(videoMode, windowTitle, Style::Titlebar | Style::Close),
	mShipTexture(loadTexture("ShipSprite.psd")),
	mCoinTexture(loadTexture("CoinSprite.psd")),
	mAsteroidTexture(loadTexture("AsteroidSprite.psd")),
	mShip(createShip()),
	mCoin(createCoin()),
	mAsteroids(),
	mSpawnTime(0.0f),
	mGameOver(false)
{
	setFramerateLimit();
	initilizeRandomizer();
}


void Game::run()
{
	Clock frameClock;
	while (mRenderWindow.isOpen() && !mGameOver)
	{
		float deltaTime = frameClock.restart().asSeconds();
		handleWindowEvents();
		clearWindow();
		updateShip(deltaTime);
		updateCoin(deltaTime);
		updateAsteroids(deltaTime);
		createAsteroids(deltaTime);
		handleCoinPickup();
		handleLostCoin();
		handleAsteroidCollisions();
		drawShip();
		drawCoin();
		drawAsteroids();
		displayWindow();
	}
}

Ship* Game::createShip()
{
	Ship* ship = new Ship;
	return ship;
}

Coin* Game::createCoin()
{
	Coin* coin = new Coin;
	return coin;
}

Texture Game::loadTexture(string fileName)
{
	Texture tex;
	tex.loadFromFile(fileName);
	return tex;
}

void Game::handleWindowEvents()
{

}

void Game::clearWindow()
{

}

void Game::updateShip(float deltaTime)
{

}

void Game::updateCoin(float deltaTime)
{

}

void Game::updateAsteroids(float deltaTime)
{

}

void Game::createAsteroids(float deltaTime)
{

}

void Game::handleCoinPickup()
{

}

void Game::handleLostCoin()
{

}

void Game::handleAsteroidCollisions()
{

}

void Game::drawShip()
{

}

void Game::drawCoin()
{

}

void Game::drawAsteroids()
{

}

void Game::displayWindow()
{

}

void Game::initilizeRandomizer()
{
	srand((unsigned int)time(0));
}

void Game::setFramerateLimit()
{
	mRenderWindow.setFramerateLimit(FRAMERATE_LIMIT);
}