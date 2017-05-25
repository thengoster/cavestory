#ifndef _INPUT_H
#define _INPUT_H

#include <SDL.h>
#include <map>

class Input {
public:
	/* beginNewFrame
	 * This function gets called at the beginning of each new frame
	 * to reset the keys that are no longer relevant
	 */
	void beginNewFrame();

	/* keyUpEvent
	 * This is called when a key has been released
	 */
	void keyUpEvent(const SDL_Event & event);

	/* keyDownEvent
	 * This is called when a key has been pressed
	 */
	void keyDownEvent(const SDL_Event & event);

	/* wasKeyPressed
	 * Checks if the specified key was pressed during the current frame
	 */
	bool wasKeyPressed(SDL_Scancode key);

	/* wasKeyReleased
	 * Checks if the specified key was released during the current frame
	 */
	bool wasKeyReleased(SDL_Scancode key);

	/* isKeyHeld
	 * Checks if the specified key is being held
	 */
	bool isKeyHeld(SDL_Scancode key);

private:
	/* the following maps keep a record of the state of keyboard inputs */
	std::map<SDL_Scancode, bool> _heldKeys;
	std::map<SDL_Scancode, bool> _pressedKeys;
	std::map<SDL_Scancode, bool> _releasedKeys;
};
#endif
