#ifndef BIGBULLET_H
#define BIGBULLET_H

#include"Weapon.h"
#include"MainWidget.h"
class BigBullet : public Weapon
{
public:

    BigBullet(){}
    BigBullet(int idd,int angle,int x,int y);
    void timerEvent(QTimerEvent *);
    void move(double tt);
    static int bullet1Num;
    static int bullet2Num;
};

#endif // BIGBULLET_H
