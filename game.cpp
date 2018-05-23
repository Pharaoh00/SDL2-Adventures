#include "game.h"
#include "base_sprite.h"
#include "player.h"
BaseSprite player1;
BaseSprite player2;
BaseSprite player3;
Player main_player;
SDL_Renderer* Game::renderer = nullptr;

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
        player1.init("imgs/hero.png", 0, 0, 16, 16, 100, 100);
        player2.init("imgs/girl.png", 0, 0, 32, 32, 200, 200);
        player3.init("imgs/oracle.png", 0, 0, 64, 64, 300, 300);
        main_player.init("imgs/hero.png", 0, 0, 16, 16, 400, 400);
        std::cout << "Renderer from Game class: " << renderer << std::endl;
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

void Game::gameEvent(){

	SDL_PollEvent(&GameEvent);

	switch (GameEvent.type) {
	case SDL_QUIT:
		running = false;
		break;
	}
}
void Game::gameUpdate() {

    main_player.update();
    //std::cout << "player x pos: " << main_player.getX() << std::endl;
}

void Game::gameRender() {
	SDL_RenderClear(renderer);
    player1.draw();
    player2.draw();
    player3.draw();
    main_player.draw();
	SDL_RenderPresent(renderer);
}

void Game::gameClean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}