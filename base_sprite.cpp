#include "base_sprite.h"

void BaseSprite::init(const char* path, int srcX, int srcY, int srcW, int srcH, int initX, int initY) {

    this->_srcRect.x = srcX;
    this->_srcRect.y = srcY;
    this->_srcRect.w = srcW;
    this->_srcRect.h = srcH;

    //INICIALIZANDO A POSI��O (a onde a imagem vai ser mostrada pela primeira vez)
    //Make the initialize position the same for the x and y pos
    this->_x = initX;
    this->_y = initY;
    //Position Rect initialize
    this->_dstRect.x = initX;
    this->_dstRect.y = initY;
    /*
    PARA ATUALIZAR A IMAGEM _dstRect.x e .y TEM QUE SER REPRESENTADAS NOVAMENTE EM UPDATE
    EM CADA CLASSE ESPECIFICA.
    */
    std::cout << _dstRect.x << std::endl;
    std::cout << _dstRect.y << std::endl;

    this->_imgTexture = LoadIMG::IMGload(path);

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
    N�O ESQUECER QUE O SCL/FLIP PARA A IMAGEM "FINAL", N�O DEVE FICAR EM draw,
    DEVE FICAR EM update.
    POR ALGUNS MOTIVOS:
    VAMOS SUPOR QUE O PERSONAGEM TENHA UM BUFF DE FOR�A,
    E ESSE BUFF FAZ COM QUE ELE FIQUE MAIOR, 
    EU N�O QUERO TER QUE ATUALIZAR ISSO EM draw, PORQUE � PARTE DA LOGICA DO GAME,
    EU QUERO SER CAPAZ DE ATUALIZAR ISSO EM update.

    FLIP PODE SER UMA VARIABLE DO PROPRIO SPRITE.
    UM BOOL QUE IR� PODE SER ATUALIZADO NO UPDATE NAS CLASSES PRINCIPAIS.
    */
    // scale the destination rect
    _dstRect.w = _srcRect.w * _scl;
    _dstRect.h = _srcRect.h * _scl;
    // drawing the img on screen

    SDL_RenderCopyEx(Game::getRenderer(), _imgTexture, &_srcRect, &_dstRect, NULL, NULL, flag);
}