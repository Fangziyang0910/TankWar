#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include<QGraphicsView>
#include<QKeyEvent>
#include<QPaintEvent>
#include<QPainter>
#include<QDebug>
#include"Tank.h"
#include"Wall.h"
#include"Map.h"
#include"Bullet.h"
#include"BigBullet.h"
#include"SmallBullet.h"
#include"Gartin.h"
#include"BombProp.h"
#include<QMessageBox>
#include<StartWidget.h>
#include<QMediaPlayer>
#include<QLCDNumber>
#include<QPushButton>
#include<QTimer>
#include<QFile>
#define PI  3.1415926
extern int OVER;
class MainWidget : public QGraphicsView
{
public:
    MainWidget();
    ~MainWidget();
    void Display();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *) override;
    QSet<int> pressedKeys;
    QList<QGraphicsItem *> list;
    QMediaPlayer *music;
    QLCDNumber *lcd;
    QLCDNumber *lcd1;
    int score1;
    int score2;
    QPixmap pix1 ;
    QPixmap pix2;
    static int propNum;
    QTimer *PropTime;

signals:
};

#endif // MAINWIDGET_H
