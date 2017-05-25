/* Game class
 * This class holds all information for our main game loop
 */

#include <SDL.h>
#include <algorithm> // in order to use std::min

#include "../headers/game.h"
#include "../headers/graphics.h"
#include "../headers/input.h"

namespace {
	const int FPS = 50; // same as the original Cavestory's FPS
	const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}

Game::Game()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	this->gameLoop();
}

Game::~Game()
{

}

void Game::gameLoop()
{
	Graphics graphics;
	Input input;
	SDL_Event event;

	int LAST_UPDATE_TIME = SDL_GetTicks();
	// Start the game loop
	while (1) {
		input.beginNewFrame();

		if (SDL_PollEvent(&event)) {
			// perform a handling action dependent on what event occurred
			switch (event.type) {
			case SDL_KEYDOWN:
				// don't handle a key pressed twice
				if (!event.key.repeat) {
					input.keyDownEvent(event);
				}
				break;

			case SDL_KEYUP:
				input.keyUpEvent(event);
				break;

			case SDL_QUIT:
				return;
			}
		}
		// provide another means of quitting the game via ESC key
		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true) {
			return;
		}

		// update frames
		const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
		this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME)); // make sure we limit to 50 FPS
		LAST_UPDATE_TIME = CURRENT_TIME_MS;
	}
}

void Game::draw(Graphics & graphics)
{

}

void Game::update(float elapsedTime)
{

}
