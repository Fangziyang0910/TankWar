#ifndef PROP_H
#define PROP_H

#include<EveryThing.h>
class Prop : public EveryThing
{
public:
    Prop();
    QRectF boundingRect()const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QPainterPath shape() const override;
};

#endif // PROP_H
