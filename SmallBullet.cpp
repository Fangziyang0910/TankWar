#include "SmallBullet.h"
int SmallBullet::bullet1Num=0;
int SmallBullet::bullet2Num=0;
SmallBullet::SmallBullet(int idd,int angle1,int x,int y,bool reboundd)
{
    startTimer(10);
    id=idd;
    rebound=reboundd;
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
    pix.load(":/pic/smallbullet.png");
    wtype = BULLET;
    this->setPos(x,y);
    killable=false;
    QTimer *time1=new QTimer(this);
    time1->start(200);
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
void SmallBullet::move(double tt)
{

    qreal ddx = 3*(cos(angle*PI/180.0));
    qreal ddy = 3*(sin(-angle*PI/180.0));
       if (isCrash(this->pos().x(),this->pos().y(),ddx,ddy)==1)
       {
           if(rebound)
           {
               angleChange(1);
           }
           else
           {
               die=true;
           }

       }
       else if(isCrash(this->pos().x(),this->pos().y(),ddx,ddy)==2)
       {
           if(rebound)
           {
               angleChange(2);
           }
           else
           {
               die=true;
           }
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
       qreal dx = 3*(cos(angle*PI/180.0));
       qreal dy = 3*(sin(-angle*PI/180.0));
       QPointF tmpp(this->pos().x()+dx,this->pos().y()+dy);
       this->setPos(tmpp);
}

void SmallBullet::timerEvent(QTimerEvent *)
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
        scene()->removeItem(this);

        delete this;

    }
    else
    {

    update();
    }
    }

}
int SmallBullet::isCrash(qreal x,qreal y,qreal dx,qreal dy)
{
    QList<QGraphicsItem *> list = collidingItems();
            foreach(QGraphicsItem * i , list){
            auto * item= dynamic_cast<EveryThing *>(i);
            if (item->wtype == WALL && item->getId() ==1)
            {

                if(fabs(y-item->pos().y())<=8&&
                        (fabs(x-item->pos().x()+58)<0.5||fabs(x-item->pos().x()-58)<0.5))
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
                        (fabs(x-item->pos().x()+58)<0.5||fabs(x-item->pos().x()-58)<0.5))
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
