#ifndef BULLET_H
#define BULLET_H


#include"Weapon.h"
#include"MainWidget.h"
class Bullet : public Weapon
{
public:
    Bullet(){}
    ~Bullet();
    Bullet(int idd,int angle,int x,int y);
    void timerEvent(QTimerEvent *);
    void move(double tt);
    static int bullet1Num;
    static int bullet2Num;
};

#endif // BULLET_H
