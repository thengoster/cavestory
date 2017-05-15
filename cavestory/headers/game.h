#ifndef _GAME_H
#define _GAME_H

class Graphics;

class Game {
public:
	Game();
	~Game();

private:
	void gameLoop();
	void draw(Graphics & graphics);
	void update(float elapsedTime);
};

#endif
