#include "base_sprite.h"

class Player : public BaseSprite {
public:
    void init(const char* path, int srcX, int srcY, int srcW, int srcH, int initX, int initY);
    void update();
    //bool boundaries();

private:
};