#include "loadimg.h"

SDL_Texture* LoadIMG::IMGload(const char* path) {

    SDL_Surface* tempSurface = IMG_Load(path); // create a surface for load the img;
    SDL_SetSurfaceRLE(tempSurface, 1);
    SDL_LockSurface(tempSurface);
    std::cout << "Need to lock: " << SDL_MUSTLOCK(tempSurface) << std::endl;
    SDL_Texture* imgTexture = SDL_CreateTextureFromSurface(Game::getRenderer(), tempSurface); // creating texture from the Surface
    SDL_UnlockSurface(tempSurface);
    SDL_FreeSurface(tempSurface); // free the surface (because we don't need enymore)
    std::cout << "Texture from LoadIMG Class: " << imgTexture << std::endl; // Testing the pointer
    std::cout << "Renderer from loadIMG: " << Game::getRenderer() << std::endl;

    return imgTexture; // the function return the texture which hold the img loaded for use
}