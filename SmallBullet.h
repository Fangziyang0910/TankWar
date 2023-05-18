#ifndef SMALLBULLET_H
#define SMALLBULLET_H

#include"Weapon.h"
#include"MainWidget.h"
class SmallBullet :public Weapon
{
public:
    SmallBullet(){}
    SmallBullet(int idd,int angle,int x,int y,bool rebound);
    void timerEvent(QTimerEvent *);
    int isCrash(qreal x, qreal y, qreal dx, qreal dy);
    void move(double tt);
    bool rebound;
    static int bullet1Num;
    static int bullet2Num;
};

#endif // SMALLBULLET_H
