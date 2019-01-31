#include "../header/player.h"
#include <math.h>

void Player::init(const char* path,
                  int srcX, int srcY,
                  int w, int h,
                  int initX, int initY) {

    BaseSprite::init(path, srcX, srcY, w, h, initX, initY);
}

void Player::update() {
    
    _x += _xvel;
    _y += _yvel;
    
    _dstRect.x = _x;
    _dstRect.y = _y;

    _angle += _tempangle;

}

void Player::keyHandle(SDL_Event event) {

    if(event.type == SDL_KEYDOWN) {
        switch(event.key.keysym.sym) {
        case SDLK_LEFT:
            _xvel = -10;
            // West
            break;
        case SDLK_RIGHT:
            _xvel = 10;
            // East
            break;
        case SDLK_UP:
            _yvel = -10;
            // North
            break;
        case SDLK_DOWN:
            _yvel = 10;
            // South
            break;
        case SDLK_e:
            _tempangle = 10;
            break;
        case SDLK_q:
            _tempangle = -10;
            break;
        }
    }
    else if(event.type == SDL_KEYUP) {
        switch(event.key.keysym.sym) {
        case SDLK_LEFT:
            _xvel = 0;
            break;
        case SDLK_RIGHT:
            _xvel = 0;
            break;
        case SDLK_UP:
            _yvel = 0;
            break;
        case SDLK_DOWN:
            _yvel = 0;
            break;
        case SDLK_e:
            _tempangle = 0;
            break;
        case SDLK_q:
            _tempangle = 0;
            break;
        }
    }
}
