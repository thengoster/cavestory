#include "../headers/level.h"
#include "../headers/graphics.h"
#include <SDL.h>

Level::Level() {}

Level::Level(std::string mapName, Vector2 spawnPoint, Graphics & graphics) :
		_mapName(mapName),
		_spawnPoint(spawnPoint),
		_size(_size.zero())
{
	this->loadMap(mapName, graphics);
}

Level::~Level()
{
}

void Level::update(int elapsedTime)
{

}

void Level::draw(Graphics & graphics)
{
	// Draw the background
	SDL_Rect sourceRect = { 0, 0, 64, 64 };
	SDL_Rect destRect;
	destRect.w = 64;
	destRect.h = 64;

	for (int y = 0; y < this->_size.y / 64; y++) {
		for (int x = 0; x < this->_size.x / 64; x++) {

			destRect.x = x * 64;
			destRect.y = y * 64;

			graphics.blitSurface(this->_backgroundTexture, &sourceRect, &destRect);
		}
	}
}

void Level::loadMap(std::string mapName, Graphics & graphics)
{
	// TEMPORARY CODE TO LOAD THE BACKGROUND
	this->_backgroundTexture = SDL_CreateTextureFromSurface(graphics.getRenderer(),
		graphics.loadImage("content/backgrounds/bkBlue.png"));
	this->_size = Vector2(2 * globals::SCREEN_WIDTH, 2 * globals::SCREEN_HEIGHT);
}
