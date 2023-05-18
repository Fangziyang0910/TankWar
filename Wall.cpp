#include "Wall.h"

Wall::Wall(int idd,int x,int y)
{
    wtype = WALL;
    id =idd;
    if(id==1)
    {
        pix.load(":/pic/wall1.png");
    }
    else
    {
        pix.load(":/pic/wall2.png");
    }
    this->setPos(x,y);

}
QRectF Wall::boundingRect()const
{
    qreal adjust = 0;

    return {-pix.width()/2 - adjust,-pix.height()/2-adjust,pix.width()+ adjust*2,pix.height()+2*adjust};
}
void Wall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect().topLeft(),pix);
}
QPainterPath Wall::shape() const{
    QPainterPath bullets;
    bullets.addRect(this->boundingRect());
    return bullets;
}
