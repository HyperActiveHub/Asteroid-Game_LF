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
	Coin* coin = new Coin(mRenderWindow);
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

		if (maxY < asteroid->getPosition().y)	//Dont forget to setOrigin to middle of every sprite in the game.
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
	//asteroid->setPosition(	some random x value above yMax	)
}

Vector2f Game::getRandomSpawnPosition(float objectRadius)
{
	return Vector2f(0.0f, 0.0f);
}

Vector2f Game::getRandomAsteroidVelocity()
{
	//min: ASTEROID_MIN_VELOCITY
	//max: ASTEROID_MIN_VELOCITY + ASTEROID_DELTA_VELOCITY
	float yVelocity = 0;//= rand mellan min och max.
	return Vector2f(0.0f, yVelocity);
}

bool Game::overlap(Ship* ship, Coin* coin)
{
	//Pythagoras sats..
	//deltaX = shipX - coinX
	//deltaY = shipY - coinY
	//om deltaX^2 + deltaY^2 < (shipRadius + coinRadius)^2
	//kollision:
	return true;
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

}

void Game::drawShip()
{

}

void Game::drawCoin()
{
	mCoin->draw();
}

void Game::drawAsteroids()
{

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