#pragma once
#include "../header/game.h"
#include "../header/loadimg.h"

class BaseSprite {

 public:
    void init(const char* path,
              int srcX, int srcY,
              int w, int h,
              int initX, int initY);

    void draw();

 protected:
    int _x;
    int _y;
    int _xvel;
    int _yvel;
    double _angle = 180;
    double _tempangle;
    int _scl = 1;
    bool _flip = false;
    SDL_Texture* _imgTexture;
    SDL_Rect _srcRect;
    SDL_Rect _dstRect;
    //static para poder persistir entre as calls.
    //ou pode ser um array de bool's
    //exampe:
    //bool state[4] = {false, false, false, false};
    //state[0] == "North"
    //state[1] == "South"
    //state[2] == "West"
    //state[3] == "East"
    //static bool xState = false; // if false == "Oeste", if true "Lest"
    //static bool yState = false; // if false == "Norte", if true "Sul"
};
