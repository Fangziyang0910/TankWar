#ifndef WALL_H
#define WALL_H

#include <QObject>
#include"EveryThing.h"
class Wall : public EveryThing
{
public:
    Wall(int id,int x,int y);
    int id;
    int getId(){return id;}
    QRectF boundingRect()const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // WALL_H
