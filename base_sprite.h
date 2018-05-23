#pragma once
#include "game.h"
#include "loadimg.h"

class BaseSprite {
    
public:
    virtual void init(const char* path, int srcX, int srcY, int w, int h, int posX, int posY);
    void draw();
    //~BaseSprite();

    const inline float getX() {return this->_dstRect.x;}
    const inline float getY() {return this->_dstRect.y;}

protected:
    int _x;
    int _y;
    int _xvel;
    int _yvel;
    int _scl = 1;
    bool _flip = false;
    SDL_Texture* _imgTexture;
    SDL_Rect _srcRect;
    SDL_Rect _dstRect;
};