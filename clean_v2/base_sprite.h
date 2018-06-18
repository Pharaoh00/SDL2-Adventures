#pragma once
#include "game.h"
#include "loadimg.h"
#include "vector2d.h"

class BaseSprite {
    
public:
    virtual void init(const char* path, int srcX, int srcY, int w, int h, Vector2D vec);
    virtual void init(const char* path, Vector2D vec);
    void draw();
    //~BaseSprite();

    const inline int getX() { return this->_spritePos.x; }
    const inline int getY() { return this->_spritePos.y; }

    int setScl(int scl);

protected:
    Vector2D _spritePos;
    Vector2D _spriteVel;
    int _scl = 1;
    bool _flip = false;
    SDL_Texture* _imgTexture;
    SDL_Rect _srcRect;
    SDL_Rect _dstRect;
};