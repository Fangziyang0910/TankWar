#include "BigBullet.h"

int BigBullet::bullet1Num=0;
int BigBullet::bullet2Num=0;
BigBullet::BigBullet(int idd,int angle1,int x,int y)
{
    startTimer(2);
    id=idd;
    if(id==1)
    {
        bullet1Num++;
    }
    else
    {
        bullet2Num++;
    }
    angle=angle1;
    die=false;
    pix.load(":/pic/bigbullet.png");
    wtype = BULLET;
    this->setPos(x,y);
    killable=false;
    QTimer *time1=new QTimer(this);
    time1->start(500);
    connect(time1,&QTimer::timeout,[=](){
        killable=true;
        time1->stop();
        delete time1;
    });
    QTimer *time2=new QTimer(this);
    time2->start(8000);
    connect(time2,&QTimer::timeout,[=](){
        die=true;
        time2->stop();
        delete time2;
    });
}
void BigBullet::move(double tt)
{

    qreal ddx = 0.4*(cos(angle*PI/180.0));
    qreal ddy = 0.4*(sin(-angle*PI/180.0));
       if (isCrash(this->pos().x(),this->pos().y(),ddx,ddy)==1)
       {
           angleChange(1);
       }
       else if(isCrash(this->pos().x(),this->pos().y(),ddx,ddy)==2)
       {
           angleChange(2);
       }
       else if(isCrash(this->pos().x(),this->pos().y(),ddx,ddy)==3)
       {
           if(killable)
           {
               die=true;
               OVER=(this->id==1?2:1);
           }
       }
       else if(isCrash(this->pos().x(),this->pos().y(),ddx,ddy)==4)
       {
            die=true;
           OVER=this->id;
       }
       qreal dx = 0.4*(cos(angle*PI/180.0));
       qreal dy = 0.4*(sin(-angle*PI/180.0));
       QPointF tmpp(this->pos().x()+dx,this->pos().y()+dy);
       this->setPos(tmpp);
}



void BigBullet::timerEvent(QTimerEvent *)
{
    if(OVER==0)
    {
    move(1);
    if(die)
    {
        if(id==1)
        {
            bullet1Num--;
        }
        else
        {
            bullet2Num--;
        }

        SmallBullet *x;
        for(int i =0;i<30;i++)
        {
            x=new SmallBullet(this->id,rand()%360,this->pos().x(),this->pos().y(),0);
            scene()->addItem(x);
        }
        scene()->removeItem(this);
        delete this;

    }
    else
    {

    update();
    }
    }

}
