#ifndef WEAPON_H
#define WEAPON_H

#include <QObject>
#include<QTimer>
#include<QVector>
#include<QMediaPlayer>
#include<EveryThing.h>
#include <QGraphicsItem>
#include<QGraphicsView>
#include <QDebug>
#include<QPaintEvent>
#include<QPainter>
#include<QTimerEvent>
#include<QGraphicsScene>
class Weapon : public EveryThing
{
public:
    Weapon();
    bool killable;
    bool die;
    void angleChange(int wallid);
    virtual int isCrash(qreal x,qreal y,qreal dx,qreal dy);
    QRectF boundingRect()const ;
    QPainterPath shape() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) ;

};

#endif // WEAPON_H
