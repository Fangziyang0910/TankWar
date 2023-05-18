#include "Prop.h"

Prop::Prop()
{

}

QRectF Prop::boundingRect() const {
    qreal adjust = 0;
    return {-pix.width()/2 - adjust,-pix.height()/2-adjust,pix.width()+ adjust*2,pix.height()+2*adjust};
}

void Prop::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

    prepareGeometryChange();
    painter->drawPixmap(boundingRect().topLeft(),pix);

}

QPainterPath Prop::shape() const{
    QPainterPath bullets;
    bullets.addRect(this->boundingRect());
    return bullets;
}
