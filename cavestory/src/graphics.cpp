/* Graphics class
 * Holds all information dealing with graphics for the game
 */

#include <SDL.h>

#include "../headers/graphics.h"

Graphics::Graphics()
{
	// &this for clarity that we need a pointer to our window/renderer pointer
	SDL_CreateWindowAndRenderer(640, 480, 0, &this->_window, &this->_renderer);
	SDL_SetWindowTitle(this->_window, "Cavestory");
}

Graphics::~Graphics()
{
	SDL_DestroyWindow(this->_window);
}
