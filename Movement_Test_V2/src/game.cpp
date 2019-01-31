#include "../header/game.h"
#include "../header/basesprite.h"
#include "../header/player.h"

BaseSprite player;
Player myPlayer;

SDL_Window* Game::window = nullptr;
SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::mainEvent;

// Main Constructor
Game::Game(const char* title, int width, int height, bool fullscreen) {
	int flag = 0;
	if (fullscreen) {
		flag = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flag);
		if (window) {
			std::cout << "Window Created!" << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			std::cout << "Render Sucess!" << std::endl;
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}
		running = true;

        player.init("assets/imgs/oracle.png", 0, 0, 64, 64, 100, 100);
        myPlayer.init("assets/imgs/triangle.png", 0, 0, 64, 64, 200, 200);
        
	}
	else {
		if (window == NULL) {
			std::cout << "Window Fail!" << std::endl;
			running = false;
		}
	}
}

Game::~Game() {
}

void Game::gameEvent() {

	SDL_PollEvent(&mainEvent);

	switch (mainEvent.type) {
	case SDL_QUIT:
		running = false;
		break;
	}

    myPlayer.keyHandle(mainEvent);
}

void Game::gameUpdate() {

    myPlayer.update();
}

void Game::gameRender() {
	SDL_RenderClear(renderer);

    player.draw();
    myPlayer.draw();

	SDL_RenderPresent(renderer);
}

void Game::gameClean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
