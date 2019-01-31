#include "../header/basesprite.h"

void BaseSprite::init(const char* path,
                      int srcX, int srcY,
                      int w, int h,
                      int initX, int initY) {

    this->_imgTexture = LoadImg::load(path);
    
    this->_srcRect.x = srcX;
    this->_srcRect.y = srcY;
    this->_srcRect.w = w;
    this->_srcRect.h = h;

    this->_x = initX;
    this->_y = initY;
    
    this->_dstRect.x = _x;
    this->_dstRect.y = _y;
}

void BaseSprite::draw() {

    _dstRect.w = _srcRect.w * _scl;
    _dstRect.h = _srcRect.h * _scl;

    SDL_RenderCopyEx(Game::getRenderer(), _imgTexture,
                     &_srcRect, &_dstRect,
                     _angle, NULL,
                     SDL_FLIP_NONE);
}
