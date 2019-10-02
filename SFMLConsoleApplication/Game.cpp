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
		drawCoin();
		drawShip();
		drawAsteroids();
		displayWindow();
	}
}

Ship* Game::createShip()
{
	float x = mRenderWindow.getSize().x * 0.5f;

	Ship* ship = new Ship(mRenderWindow, mShipTexture, Vector2f(x, 300), SHIP_VELOCITY, SHIP_RADIUS);
	return ship;
}

Coin* Game::createCoin()
{
	float x = mRenderWindow.getSize().x * 0.5f;
	Coin* coin = new Coin(mRenderWindow, mCoinTexture, Vector2f(x, 300), Vector2f(0, COIN_VELOCITY), COIN_RADIUS);
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
	Event event;
	while (mRenderWindow.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			mRenderWindow.close();
		}
	}
}

void Game::clearWindow()
{
	mRenderWindow.clear();
}

void Game::updateShip(float deltaTime)
{
	mShip->update(deltaTime);
}

void Game::updateCoin(float deltaTime)
{
	mCoin->update(deltaTime);
}

void Game::updateAsteroids(float deltaTime)
{
	float maxY = mRenderWindow.getSize().y + ASTEROID_RADIUS;
	for (AsteroidVector::size_type i = 0; i < mAsteroids.size(); i++)
	{
		Asteroid* asteroid = mAsteroids[i];
		asteroid->update(deltaTime);

		if (maxY < asteroid->getPosition().y)
		{
			resetAsteroid(asteroid);
		}
	}
}

void Game::createAsteroids(float deltaTime)
{
	mSpawnTime += deltaTime;
	if (ASTEROID_SPAWN_DELTA < mSpawnTime)
	{
		Asteroid* asteroid = new Asteroid(mRenderWindow, mAsteroidTexture, getRandomSpawnPosition(ASTEROID_RADIUS), getRandomAsteroidVelocity(), ASTEROID_RADIUS);
		mAsteroids.push_back(asteroid);
		mSpawnTime = 0.0f;
	}
}

void Game::resetAsteroid(Asteroid* asteroid)
{
	float offsetY = -ASTEROID_RADIUS;
	float offsetX = (float)(rand() % mRenderWindow.getSize().x);

	asteroid->setPosition(Vector2f(offsetX, offsetY));
}

Vector2f Game::getRandomSpawnPosition(float objectRadius)
{
	float offsetX = (float)(rand() % mRenderWindow.getSize().x);

	return Vector2f(offsetX, -objectRadius);
}

Vector2f Game::getRandomAsteroidVelocity()
{
	float yVelocity = rand() % (int)(ASTEROID_MIN_VELOCITY + ASTEROID_DELTA_VELOCITY - ASTEROID_MIN_VELOCITY + 1) + ASTEROID_MIN_VELOCITY;
	return Vector2f(0.0f, yVelocity);
}

bool Game::overlap(Ship * ship, Coin * coin)
{
	float deltaX = ship->getPosition().x - coin->getPosition().x;
	float deltaY = ship->getPosition().y - coin->getPosition().y;

	if (pow(deltaX, 2) + pow(deltaY, 2) < pow(SHIP_RADIUS + COIN_RADIUS, 2))
	{
		return true;
	}
	return false;
}

bool Game::overlap(Ship * ship, AsteroidVector asteroids)
{
	for (auto asteroid : asteroids)
	{
		float deltaX = ship->getPosition().x - asteroid->getPosition().x;
		float deltaY = ship->getPosition().y - asteroid->getPosition().y;

		if (pow(deltaX, 2) + pow(deltaY, 2) < pow(SHIP_RADIUS + ASTEROID_RADIUS, 2))
		{
			return true;
		}
	}
	return false;
}

void Game::handleCoinPickup()
{
	if (overlap(mShip, mCoin))
	{
		resetCoin();
	}
}

void Game::resetCoin()
{
	float offsetY = -COIN_RADIUS;
	float offsetX = (float)(rand() % mRenderWindow.getSize().x);

	mCoin->setPosition(Vector2f(offsetX, offsetY));
}

void Game::handleLostCoin()
{
	float maxY = COIN_RADIUS + mRenderWindow.getSize().y;

	if (maxY < mCoin->getPosition().y)
	{
		mGameOver = true;
	}
}

void Game::handleAsteroidCollisions()
{
	if (overlap(mShip, mAsteroids))
	{
		mGameOver = true;
	}
}

void Game::drawShip()
{
	mShip->draw();
}

void Game::drawCoin()
{
	mCoin->draw();
}

void Game::drawAsteroids()
{
	for (auto asteroid : mAsteroids)
	{
		asteroid->draw();
	}
}

void Game::displayWindow()
{
	mRenderWindow.display();
}

void Game::initilizeRandomizer()
{
	srand((unsigned int)time(0));
}

void Game::setFramerateLimit()
{
	mRenderWindow.setFramerateLimit(FRAMERATE_LIMIT);
}