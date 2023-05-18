#include "StartWidget.h"
#include "ui_StartWidget.h"
#include"MainWidget.h"
#include<QDebug>
#include<GameRecord.h>
StartWidget::StartWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartWidget)
{

    ui->setupUi(this);
    startTimer(200);
    backGround=new QImage(":/pic/tankbackground.jpeg");
    status = 1;
    connect(ui->Start2P,&QPushButton::clicked,[=](){

        auto*mw=new MainWidget;
        mw->Display();
        this->hide();

    });
    connect(ui->startHelp,&QPushButton::clicked,[=](){

            auto* hw=new HelpWidget;
            hw->show();

    });
    connect(ui->GameRecordButton,&QPushButton::clicked,[=](){

            auto* hw=new GameRecord;
            hw->show();

    });

}

void StartWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    Q_UNUSED(event);
    setFixedSize(800,600);
    paint.begin(this);
    paint.drawImage(QRect(0,0,800,600),*backGround);
    paint.end();
}
void StartWidget::timerEvent(QTimerEvent *)
{

}

StartWidget::~StartWidget()
{
    delete ui;
}
