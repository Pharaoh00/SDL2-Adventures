//basesprite.cpp
#include "basesprite.h"

void BaseSprite::init(const char* path, int srcX, int srcY, int w, int h, Vector2Df vec) {

    this->_spriteTexture = LoadIMG::load(path); //Criando e carregando texture para usar

    this->_srcRect.x = srcX; //Inicializando x crop
    this->_srcRect.y = srcY; //Inicializando y crop
    this->_srcRect.w = w; //Inicializando widht
    this->_srcRect.h = h; //Inicializando height

    this->_dstRect.x = vec.x; //Inicializando x pos com Vector2Df (float)
    this->_dstRect.y = vec.y; //Inicializando y pos com Vector2Df (float)
}

void BaseSprite::init(const char* path, Vector2Df vec) {

    this->_spriteTexture = LoadIMG::load(path); //Criando e carregando texture para usar
    SDL_QueryTexture(_spriteTexture, NULL, NULL, &_srcRect.w, &_srcRect.h); //Pegando "automaticamente" as dimensões do source Rect

    this->_dstRect.x = vec.x; //Inicializando x pos com Vector2Df (float)
    this->_dstRect.y = vec.y; //Inicializando y pos com Vector2Df (float)
}

void BaseSprite::draw() {
    
    if (_flip) {
        flag = SDL_FLIP_HORIZONTAL; //flip horizontalmente
    }
    else if (!_flip) {
        flag = SDL_FLIP_NONE; // not flip the image
    }

    _dstRect.w = _srcRect.w * _scl; //dimensões do source Rect * scale
    _dstRect.h = _srcRect.h * _scl; //dimensões do source Rect * scale

    SDL_RenderCopyEx(Game::getRenderer(), _spriteTexture, &_srcRect, &_dstRect, NULL, NULL, flag); //drawing the texture on screen
}