#include "../header/player.h"
#include <math.h>

void Player::init(const char* path,
                  int srcX, int srcY,
                  int w, int h,
                  int initX, int initY) {

    BaseSprite::init(path, srcX, srcY, w, h, initX, initY);
}

void Player::update() {

    // _angle = fmod(_angle, 360);
    
    
    // _x += _xvel;
    _y += _yvel;
    
    _dstRect.x = _x;
    _dstRect.y = _y;

    _angle += _tempangle;

}

void Player::keyHandle(SDL_Event event) {

    if(event.type == SDL_KEYDOWN) {
        switch(event.key.keysym.sym) {
        case SDLK_UP:
            _yvel = 1;
            // North
            break;
        case SDLK_DOWN:
            _yvel = -1;
            // South
            break;
        case SDLK_LEFT:
            _tempangle = 1;
            break;
        case SDLK_RIGHT:
            _tempangle = -1;
            break;
        }
    }
    else if(event.type == SDL_KEYUP) {
        switch(event.key.keysym.sym) {
        case SDLK_LEFT:
            _tempangle = 0;
            break;
        case SDLK_RIGHT:
            _tempangle = 0;
            break;
        }
    }
}
