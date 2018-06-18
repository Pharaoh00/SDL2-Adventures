#pragma once
#include "game.h"
#include "SDL_image.h"
#include <map>

struct LoadIMG {

    static SDL_Texture* load(const char* path);
};