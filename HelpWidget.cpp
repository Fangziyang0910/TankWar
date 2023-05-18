#include "HelpWidget.h"
#include "ui_HelpWidget.h"

HelpWidget::HelpWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HelpWidget)
{
    ui->setupUi(this);

    ui->player1explain->setStyleSheet("background-color: rgb(255, 255, 255, 0);");
    ui->player2explain->setStyleSheet("background-color: rgb(255, 255, 255, 0);");
    connect(ui->backToStart,&QPushButton::clicked,[=](){
        delete this;
    });
}

HelpWidget::~HelpWidget()
{
    delete ui;
}
