#include "player.h"

void Player::init(const char* path, int srcX, int srcY, int srcW, int srcH, int initX, int initY) {
    BaseSprite::init(path, srcX, srcY, srcW, srcH, initX, initY);
    std::cout << "From Class Player!" << std::endl;
}

void Player::update() {
    _dstRect.x += 1;
    if (_dstRect.x > 640) {
        _dstRect.x -= 1;
    }
    else if(_dstRect.x < 0) {
        _dstRect.x += 1;
    }

    std::cout << _dstRect.x << std::endl;
    //std::cout << "Player x pos: " << _x << std::endl;
}