#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

class Game {
private:
	SDL_Window* window;
    static SDL_Renderer* renderer;
    SDL_Event GameEvent;

public:
	Game(const char* title, int width, int height, bool fullscreen =  false);
	~Game();

	bool running;
    static SDL_Renderer* getRenderer() { return renderer; }

	void gameEvent();
	void gameUpdate();
	void gameRender();
	void gameClean();
};