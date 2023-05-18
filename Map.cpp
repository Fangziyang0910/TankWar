#include "Map.h"

Map::Map()
{
    for(int i =0;i<8;i++)
    {
        for(int j = 0;j<8;j++)
        {
            cell[i][j].x = i;
            cell[i][j].y = j;
            cell[i][j].right=true;
            cell[i][j].down=true;
            cell[i][j].full=false;
            cell[i][j].walled=false;
        }
    }
    srand((unsigned int)(time(NULL)));
    qDebug()<<rand();
    road.push_back(cell[0][0]);
    cell[0][0].walled=true;
    findRoad();
}
//Map::~Map()
//{
//    for(int i =0;i<wall.size();i++)
//    {
//        delete (wall[i]);
//    }
//}
void Map::findRoad()
{
    while(road.size())
    {
        int b =((rand())%(road.size()));
        if(checkfull(road[b].x,road[b].y))
        {
            road.erase(road.begin()+b);
            continue;
        }
        delWall(road[b].x,road[b].y);
    }
}
bool Map::checkfull(int x,int y)
{
    int sum=0;
    if(x-1<0)
    {
        sum++;
    }
    else
    {
        if(cell[x-1][y].walled==true)
        {
            sum++;
        }
    }
    if(y-1<0)
    {
        sum++;
    }
    else
    {
        if(cell[x][y-1].walled==true)
        {
            sum++;
        }
    }
    if(x+1>=8)
    {
        sum++;
    }
    else
    {
        if(cell[x+1][y].walled==true)
        {
            sum++;
        }
    }
    if(y+1>=8)
    {
        sum++;
    }
    else
    {
        if(cell[x][y+1].walled==true)
        {
            sum++;
        }
    }
    if(sum==4)
    {
        cell[x][y].full=true;
        return true;
    }
    else
    {
        return false;
    }
}
void Map::delWall(int x,int y)
{
    int status=1;
    while(status)
    {
        int a =rand()%4;
        if(a==0)
        {
            if(x-1>=0&&cell[x-1][y].walled==false)
            {
                cell[x-1][y].down=false;
                road.push_back(cell[x-1][y]);
                cell[x-1][y].walled=true;
                status=0;
                break;
            }
        }
        if(a==1)
        {
            if(y-1>=0&&cell[x][y-1].walled==false)
            {
                cell[x][y-1].right=false;
                road.push_back(cell[x][y-1]);
                cell[x][y-1].walled=true;
                status=0;
                break;
            }
        }
        if(a==2)
        {
            if(x+1<8&&cell[x+1][y].walled==false)
            {
                cell[x][y].down=false;
                road.push_back(cell[x+1][y]);
                cell[x+1][y].walled=true;
                status=0;
                 break;
            }
        }
        if(a==3)
        {
            if(y+1<8&&cell[x][y+1].walled==false)
            {
                cell[x][y].right=false;
                road.push_back(cell[x][y+1]);
                cell[x][y+1].walled=true;
                status=0;
                 break;
            }
        }

    }
}

