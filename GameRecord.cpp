#include "GameRecord.h"
#include "ui_GameRecord.h"
#include<QFile>
#include<QApplication>
GameRecord::GameRecord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameRecord)
{
    ui->setupUi(this);
        QString path = QApplication::applicationDirPath();
        path += "/GameRecord.txt";
        QFile file(path);
        file.open(QIODevice::ReadOnly);
        QByteArray array = file.readAll();
        ui->textEdit->setText(array);
        file.close();
}

GameRecord::~GameRecord()
{
    delete ui;
}
