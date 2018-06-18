#include "base_sprite.h"

void BaseSprite::init(const char* path, int srcX, int srcY, int w, int h, Vector2D vec) {

    this->_imgTexture = LoadIMG::IMGload(path);

    this->_srcRect.x = srcX;
    this->_srcRect.y = srcY;
    this->_srcRect.w = w;
    this->_srcRect.h = h;

    //INICIALIZANDO A POSIÇÃO (a onde a imagem vai ser mostrada pela primeira vez)
    //Make the initialize position the same for the x and y pos
    //this->_x = initX;
    //this->_y = initY;
    //Position Rect initialize
    this->_dstRect.x = vec.x;
    this->_dstRect.y = vec.y;
    /*
    PARA ATUALIZAR A IMAGEM _dstRect.x e .y TEM QUE SER REPRESENTADAS NOVAMENTE EM UPDATE
    EM CADA CLASSE ESPECIFICA.
    */
}

void BaseSprite::init(const char* path, Vector2D vec) {

    this->_imgTexture = LoadIMG::IMGload(path);
    SDL_QueryTexture(_imgTexture, NULL, NULL, &_srcRect.w, &_srcRect.h);

    this->_dstRect.w = this->_srcRect.w;
    this->_dstRect.h = this->_srcRect.h;

    this->_dstRect.x = vec.x;
    this->_dstRect.y = vec.y;
    
}

int BaseSprite::setScl(int scl) {
    _scl = scl;
    return _scl;
}

void BaseSprite::draw() {

    SDL_RendererFlip flag;
    if (_flip) {
        flag = SDL_FLIP_HORIZONTAL; // flip the image on the y axis
    }
    if (!_flip) {
        flag = SDL_FLIP_NONE; // not flip the image
    }
    /*
    NÃO ESQUECER QUE O SCL/FLIP PARA A IMAGEM "FINAL", NÃO DEVE FICAR EM draw,
    DEVE FICAR EM update.
    POR ALGUNS MOTIVOS:
    VAMOS SUPOR QUE O PERSONAGEM TENHA UM BUFF DE FORÇA,
    E ESSE BUFF FAZ COM QUE ELE FIQUE MAIOR, 
    EU NÃO QUERO TER QUE ATUALIZAR ISSO EM draw, PORQUE É PARTE DA LOGICA DO GAME,
    EU QUERO SER CAPAZ DE ATUALIZAR ISSO EM update.

    FLIP PODE SER UMA VARIABLE DO PROPRIO SPRITE.
    UM BOOL QUE IRÁ PODE SER ATUALIZADO NO UPDATE NAS CLASSES PRINCIPAIS.
    */
    // scale the destination rect
    _dstRect.w = _srcRect.w * _scl;
    _dstRect.h = _srcRect.h * _scl;
    // drawing the img on screen
    SDL_RenderCopyEx(Game::getRenderer(), _imgTexture, &_srcRect, &_dstRect, NULL, NULL, flag);
}