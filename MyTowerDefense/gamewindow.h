#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QList>
#include "myobject.h"
#include <QPushButton>
class WayPoint;
class Enemy;
class Bullet;

class GameWindow : public QMainWindow
{
    Q_OBJECT
public:
    GameWindow(int);
    void paintEvent(QPaintEvent *);
    void addWayPoints();
    QList<WayPoint *>m_wayPointsList;
//    QList<Enemy *>m_enemyList;
    void addMyobject();
    void updateScene();
private:
    int levelNumber;//关卡数
    //QList<Tower*> tower_list;
    QList<MyObject*> object_list;


signals:
    void chooseBack();


};

#endif // GAMEWINDOW_H
