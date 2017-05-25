#ifndef _GRAPHICS_H
#define _GRAPHICS_H

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
	/* Graphics
	 * creates window and renderer using SDL
	 */
	Graphics();

	/* ~Graphics
	 * destroys any window/renderer that goes out of scope
	 */
	~Graphics();

private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;
};

#endif
