#ifndef TANK_H
#define TANK_H

#include <QGraphicsItem>
#include <QDebug>
#include"EveryThing.h"
#include<QPaintEvent>
#include<QPainter>
#include<QTimerEvent>
#include<QTimer>
#include<Bullet.h>
#include<QMediaPlayer>
class Tank : public EveryThing
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    Tank(int idd,int x,int y,int face);
    ~Tank();
    QRectF boundingRect()const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QPainterPath shape() const override;
    void move(double t);
    void timerEvent(QTimerEvent *event);

    bool movable(qreal x, qreal y);
    void fire();
    int UP,DOWN,RIGHT,LEFT,FIRE;
    int posx;
    int posy;
    int bulletNum;
    int fireStatus;
    QVector<QMediaPlayer*>musicList;


private:

signals:

public slots:
};

#endif // TANK_H
