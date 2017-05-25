#include "../headers/sprite.h"
#include "../headers/graphics.h"
#include "../headers/globals.h"

Sprite::Sprite() {}

Sprite::Sprite(Graphics & graphics, const std::string & filePath, int sourceX, int sourceY,
		int width, int height, float posX, float posY) : 
			_x(posX), _y(posY)
{
	this->_sourceRect.x = sourceX;
	this->_sourceRect.y = sourceY;
	this->_sourceRect.w = width;
	this->_sourceRect.h = height;

	// the surface is our spritesheet image file
	// convert to texture so that we can use hardware rendering in GPU instead of software in CPU
	this->_spriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));
	if (this->_spriteSheet == NULL) {
		printf("\nError: Unable to load image\n");
	}
}

Sprite::~Sprite() {}

void Sprite::update() {}

void Sprite::draw(Graphics & graphics, int x, int y)
{
	SDL_Rect destinationRectangle = { x, y, (int) (this->_sourceRect.w * globals::SPRITE_SCALE), 
			(int) (this->_sourceRect.h * globals::SPRITE_SCALE) };
	graphics.blitSurface(this->_spriteSheet, &this->_sourceRect, &destinationRectangle);
}
