#pragma once
#include "../header/basesprite.h"

class Player : virtual public BaseSprite {

 public:
    void init(const char* path,
              int srcX, int srcY,
              int w, int h,
              int initX, int initY);
    void update();
    void keyHandle(SDL_Event event);
};
