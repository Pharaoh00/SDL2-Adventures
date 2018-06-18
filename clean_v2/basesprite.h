#pragma once
//basesprite.h

#include "game.h"
#include "loadimg.h"
#include "vector2d.h"

class BaseSprite {

public:
    virtual void init(const char* path, int srcX, int srcY, int w, int h, Vector2Df vec);
    virtual void init(const char* path, Vector2Df vec);
    void draw();

    const inline int getX() { return this->_dstRect.x; }
    const inline int getX() { return this->_dstRect.y; }

    void setScl(int scl) { this->_scl = scl; };
    void flip(bool flip) { this->_flip = flip; };

private:
    int _scl = 1;
    bool _flip = false;
    SDL_RendererFlip flag;
    SDL_Texture* _spriteTexture;
    SDL_Rect _srcRect;
    SDL_Rect _dstRect;
};