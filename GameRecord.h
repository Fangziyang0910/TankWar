#ifndef GAMERECORD_H
#define GAMERECORD_H

#include <QDialog>

namespace Ui {
class GameRecord;
}

class GameRecord : public QDialog
{
    Q_OBJECT

public:
    explicit GameRecord(QWidget *parent = nullptr);
    ~GameRecord();

private:
    Ui::GameRecord *ui;
};

#endif // GAMERECORD_H
