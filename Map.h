#ifndef MAP_H
#define MAP_H

#include <QObject>
#include<ctime>
#include<QDebug>
#include<QVector>
#include"Wall.h"
#include"MainWidget.h"
struct Cell
{
    int x;
    int y;
    bool right;
    bool down;
    bool walled;
    bool full;
};

class Map
{
public:
    Map();
    //~Map();
    Cell cell[8][8];
    QVector<Cell>road;
    QVector<Wall*>wall;
    void findRoad();
    bool checkfull(int x,int y);
    void delWall(int x,int y);
};

#endif // MAP_H
