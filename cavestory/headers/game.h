#ifndef _GAME_H
#define _GAME_H

/* Game class
 * This class holds all information for our main game loop
 */

#include "player.h"
#include "level.h"

// forward declaration of graphics class
class Graphics;

class Game {
public:
	/* Game
	 * Create the game loop by initializing everything using SDL
	 */
	Game();

	/* ~Game */
	~Game();

private:
	/* gameLoop
	* Is called every frame, IS IMPORTANT
	*/
	void gameLoop();
	
	/* draw */
	void draw(Graphics & graphics);

	/* update */
	void update(float elapsedTime);

	Player _player;

	Level _level;
};

#endif
