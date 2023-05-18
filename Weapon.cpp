#include "Weapon.h"

Weapon::Weapon()
{

}
void Weapon::angleChange(int wallid)
{
    if(wallid==1)
    {
        if(angle<=90)
        {
            angle=-angle;
        }
        else if(angle<=180)
        {
            angle+=2*(180-angle);
        }
        else if(angle<=270)
        {
            angle-=2*(angle-180);
        }
        else if(angle<=360)
        {
            angle+=2*(360-angle);
        }
    }
    if(wallid==2)
    {
        if(angle<=180)
        {
            angle=180-angle;
        }
        else if(angle<=360)
        {
            angle=360-(angle%180);
        }
    }
    if (angle>=360)
    {
        angle-=360;
    }
    if(angle<0)
    {
        angle+=360;
    }
}
int Weapon::isCrash(qreal x,qreal y,qreal dx,qreal dy)
{
    QList<QGraphicsItem *> list = collidingItems();
            foreach(QGraphicsItem * i , list){
            auto * item= dynamic_cast<EveryThing *>(i);
            if (item->wtype == WALL && item->getId() ==1)
            {

                if(fabs(y-item->pos().y())<=8&&
                        (fabs(x-item->pos().x()+58)<1||fabs(x-item->pos().x()-58)<1))
                {
                    return 2;
                }
                else
                {
                return 1;
                }
            }
            if (item->wtype == WALL && item->getId() ==2)
            {

                if(fabs(x-item->pos().x())<=8&&
                        (fabs(y-item->pos().y()+58)<1||fabs(y-item->pos().y()-58)<1))
                {
                    return 1;
                }
                else
                {
                return 2;
                }
            }
            if(item->wtype==TANK && item->getId()==this->id)
            {
               return 3;
            }
            if(item->wtype==TANK && item->getId()!=this->id)
            {
               return 4;
            }

}
            return 0;
}
QRectF Weapon::boundingRect() const {
    qreal adjust = 0;
    return {-pix.width()/2 - adjust,-pix.height()/2-adjust,pix.width()+ adjust*2,pix.height()+2*adjust};
}

void Weapon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

    prepareGeometryChange();
    painter->drawPixmap(boundingRect().topLeft(),pix);

}

QPainterPath Weapon::shape() const{
    QPainterPath bullets;
    bullets.addRect(this->boundingRect());
    return bullets;
}
