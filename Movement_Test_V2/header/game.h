#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 554;

class Game {
private:
	static SDL_Window* window;
	static SDL_Renderer* renderer;
	static SDL_Event mainEvent;

public:
	Game(const char* title, int width, int height, bool fullscreen = false);
	~Game();

	bool running;
    static SDL_Window* getWindow() { return window; }
	static SDL_Renderer* getRenderer() { return renderer; }
	static SDL_Event getEvent() { return mainEvent; }

	void gameEvent();
	void gameUpdate();
	void gameRender();
	void gameClean();
};
