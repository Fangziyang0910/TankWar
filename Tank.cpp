#include "Tank.h"
#include<QPainter>
#include <QGraphicsScene>
Tank::Tank(int idd,int x,int y,int face)
{
    startTimer(10);
    id=idd;
    angle=0;
    posx=x;
    posy=y;
    fireStatus=1;
    if(id==1)
    {
        pix.load(":/pic/tank1.png");
    }
    else
    {
        pix.load(":/pic/tank2.png");
    }
    wtype = TANK;
    FIRE=UP=DOWN=RIGHT=LEFT=0;
    bulletNum=0;
    angle=face*90;

}
Tank::~Tank()
{
    for(int i =0;i<musicList.size();i++)
    {
        delete musicList[i];
    }
}

void Tank::paint(QPainter* painter, const QStyleOptionGraphicsItem*option, QWidget*widget)
{

    prepareGeometryChange();
    painter->drawPixmap(boundingRect().topLeft(), pix);
}
QRectF Tank::boundingRect() const
{
    qreal adjust = 0;
    return {-pix.width()/2 - adjust,-pix.height()/2-adjust,pix.width(),pix.height()+2*adjust};
}
void Tank::timerEvent(QTimerEvent *event)
{
    if(OVER==0)
    {

        if(FIRE&&fireStatus)
        {
            fire();
        }

    move(1);
    update();
    }

}
QPainterPath Tank::shape() const{
    QPainterPath bullets;
    bullets.addRect(this->boundingRect());
    return bullets;
}
void Tank::move(double tt) {

    double x = UP - DOWN;   //上1  下 -1
       double y = LEFT - RIGHT;  //左1 右 -1
       qreal dx = x*2*(cos(angle*PI/180.0));
       qreal dy = x*2*(sin(-angle*PI/180.0));
       if (!movable(this->pos().x()+dx,this->pos().y()+dy)) return;
       if (angle>=360)
       {
           angle-=360;
       }
       if(angle<0)
       {
           angle+=360;
       }
       angle += y*2 ;
       double tmp = -angle;
       this->setRotation(tmp);
       if (!movable(this->pos().x(),this->pos().y())){
           angle -=y*2;
           this->setRotation(-angle);
       }
       QPointF tmpp(this->pos().x()+dx,this->pos().y()+dy);
       this->setPos(tmpp);
       if (!movable(this->pos().x(),this->pos().y())){
           this->setPos(QPointF(this->pos().x()-dx,this->pos().y()-dy));
       }

}
bool Tank::movable(qreal x,qreal y) {
    bool temp=true;
    QList<QGraphicsItem *> list = collidingItems();
            foreach(QGraphicsItem * i , list) {
            auto *item = dynamic_cast<EveryThing *>(i);
            if (item->wtype == WALL) {
                temp=false;
            }
            else if(item->wtype ==PROP)
            {
                if(item->id==1)
                {
                    fireStatus=2;
                }
                else
                {
                    fireStatus=3;
                }
                MainWidget::propNum--;
                delete item;
            }

        }
            return temp;
}
void Tank::fire() {
if(fireStatus==1)
{
        if(id==1&&Bullet::bullet1Num<8||id==2&&Bullet::bullet2Num<8)
        {
            QMediaPlayer *music = new QMediaPlayer();
            music->setMedia(QUrl("qrc:/sound/TankFire.wav"));
            musicList.push_back(music);
            music->play();
        Bullet *x=new Bullet(this->id,this->angle,this->pos().x(),this->pos().y());
        scene()->addItem(x);
        fireStatus=0;
        QTimer *time = new QTimer(this);
        time->start(150);
        connect(time,&QTimer::timeout,[=](){
            fireStatus=1;
            time->stop();
            delete time;
        });
        }
}
else if(fireStatus==2)
{
    if(id==1&&Bullet::bullet1Num<1||id==2&&Bullet::bullet2Num<1)
    {
        QMediaPlayer *music = new QMediaPlayer();
        music->setMedia(QUrl("qrc:/sound/TankFire.wav"));
        musicList.push_back(music);
        music->play();
    BigBullet *x=new BigBullet(this->id,this->angle,this->pos().x(),this->pos().y());
    scene()->addItem(x);
    fireStatus=0;
    QTimer *time = new QTimer(this);
    time->start(2000);
    connect(time,&QTimer::timeout,[=](){
        fireStatus=1;
        time->stop();
        delete time;
    });
    }
}
else if(fireStatus==3)
{
    if(id==1&&SmallBullet::bullet1Num<30||id==2&&SmallBullet::bullet2Num<30)
    {
        QMediaPlayer *music = new QMediaPlayer();
        music->setMedia(QUrl("qrc:/sound/TankFire.wav"));
        musicList.push_back(music);
        music->play();
    SmallBullet *x=new SmallBullet(this->id,this->angle-10+rand()%20,this->pos().x(),this->pos().y(),true);
    scene()->addItem(x);
    fireStatus=0;
    QTimer *time = new QTimer(this);
    QTimer *time1 = new QTimer(this);
    time->start(90);
    time1->start(10000);
    connect(time,&QTimer::timeout,[=](){
        fireStatus=3;
        time->stop();
        delete time;
    });
    connect(time1,&QTimer::timeout,[=](){
        fireStatus=1;
        time1->stop();
        delete time1;
    });
    }
}
}
