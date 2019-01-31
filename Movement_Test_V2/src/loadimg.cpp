#include "../header/loadimg.h"
#include "../header/game.h"

SDL_Texture* LoadImg::load(const char* path) {

    SDL_Surface* tempSurface = IMG_Load(path);
    SDL_Texture* imgTexture = SDL_CreateTextureFromSurface(Game::getRenderer(),
                                                           tempSurface);
    SDL_FreeSurface(tempSurface);

    return imgTexture;
};
