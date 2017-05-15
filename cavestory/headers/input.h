#ifndef _INPUT_H
#define _INPUT_H

#include <SDL.h>
#include <map>

class Input {
public:
	void beginNewFrame();
	void keyUpEvent(const SDL_Event & event);
	void keyDownEvent(const SDL_Event & event);

	bool wasKeyPressed(SDL_Scancode key);
	bool wasKeyReleased(SDL_Scancode key);
	bool isKeyHeld(SDL_Scancode key);

private:
	/* the following maps keep a record of the state of keyboard inputs */
	std::map<SDL_Scancode, bool> _heldKeys;
	std::map<SDL_Scancode, bool> _pressedKeys;
	std::map<SDL_Scancode, bool> _releasedKeys;
};
#endif
