#include "BombProp.h"

BombProp::BombProp(int x,int y )
{
    id=1;
    wtype=PROP;
    pix.load(":/pic/bombbullet.png");
    this->setPos(x,y);
}
