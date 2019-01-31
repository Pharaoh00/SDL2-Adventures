#include "../header/game.h"

Game *game = nullptr;
const int FPS = 60;
const int frameDelay = 1000 / FPS;
Uint32 frameStart;
int frameTime;

int main(int argc, char *argv[]) {

    game = new Game("Game", SCREEN_WIDTH, SCREEN_HEIGHT);

    while(game->running) {

        frameStart = SDL_GetTicks();

        game->gameEvent();
        game->gameUpdate();
        game->gameRender();

        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->gameClean();
    return 0;
}
