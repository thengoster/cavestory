/* Input class
 * Handles keyboard interrupts (inputs) and their state
 */

#include "../headers/input.h"

/* beginNewFrame 
 * This function gets called at the beginning of each new frame
 * to reset the keys that are no longer relevant
 */
void Input::beginNewFrame()
{
	this->_pressedKeys.clear();
	this->_releasedKeys.clear();
}

/* keyUpEvent 
 * This is called when a key has been released
 */
void Input::keyUpEvent(const SDL_Event & event)
{
	this->_releasedKeys[event.key.keysym.scancode] = true;
	this->_heldKeys[event.key.keysym.scancode] = false;
}

/* keyDownEvent 
 * This is called when a key has been pressed
 */
void Input::keyDownEvent(const SDL_Event & event)
{
	this->_pressedKeys[event.key.keysym.scancode] = true;
	this->_heldKeys[event.key.keysym.scancode] = true;
}

/* wasKeyPressed 
 * Checks if the specified key was pressed during the current frame
 */
bool Input::wasKeyPressed(SDL_Scancode key)
{
	return this->_pressedKeys[key];
}

/* wasKeyReleased 
 * Checks if the specified key was released during the current frame
 */
bool Input::wasKeyReleased(SDL_Scancode key)
{
	return this->_releasedKeys[key];
}

/* isKeyHeld
 * Checks if the specified key is being held
 */
bool Input::isKeyHeld(SDL_Scancode key)
{
	return _heldKeys[key];
}
