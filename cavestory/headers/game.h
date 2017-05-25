#ifndef _GAME_H
#define _GAME_H

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
};

#endif
