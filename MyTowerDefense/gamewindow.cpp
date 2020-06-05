#include "gamewindow.h"
#include "chooselevelwindow.h"
#include "mybutton.h"
#include "waypoint.h"
#include <QPainter>
#include <QTimer>
#include <QPushButton>
#include <QPixmap>


GameWindow::GameWindow(int levelNumber): QMainWindow(0)
{
    this->levelNumber = levelNumber;
    this->setFixedSize(1500,1200);

    MyButton * back_bin = new MyButton(":/images/back-button.png");
    back_bin->setParent(this);
    back_bin->setIconSize(QSize(350,175));
    back_bin->move(-100,900);
    connect(back_bin,&MyButton::clicked,this,[=](){
        emit chooseBack();
    });

    MyButton * play = new MyButton(":/images/Button.png");
    play->setParent(this);
    play->move(1100,1010);

    connect(play,&MyButton::clicked,this,&GameWindow::addMyobject);
    QTimer * timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&GameWindow::updateScene);
    timer->start(10);


}
void GameWindow::paintEvent(QPaintEvent *){

    if(levelNumber==1){
        QPainter painter(this);
        QPixmap pixmap(":/images/01A.png");
        painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
     }
    if(levelNumber==2){
        QPainter painter(this);
        QPixmap pixmap(":/images/02A.png");
        painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
     }
    if(levelNumber==3){
        QPainter painter(this);
        QPixmap pixmap(":/images/03A.png");
        painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
     }
    if(levelNumber==4){
        QPainter painter(this);
        QPixmap pixmap(":/images/04A.png");
        painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
     }
    QPainter painter(this);
//    foreach(Tower * tower,tower_list)
//        tower->draw(&painter);
    foreach(MyObject * object,object_list)
        object->draw(&painter);

}

void GameWindow::addWayPoints()
{
    WayPoint *wayPoint1 = new WayPoint(QPoint(420, 285));
    m_wayPointsList.push_back(wayPoint1);

    WayPoint *wayPoint2 = new WayPoint(QPoint(35, 285));
    m_wayPointsList.push_back(wayPoint2);
    wayPoint2->setNextWayPoint(wayPoint1);

    WayPoint *wayPoint3 = new WayPoint(QPoint(35, 195));
    m_wayPointsList.push_back(wayPoint3);
    wayPoint3->setNextWayPoint(wayPoint2);

    WayPoint *wayPoint4 = new WayPoint(QPoint(445, 195));
    m_wayPointsList.push_back(wayPoint4);
    wayPoint4->setNextWayPoint(wayPoint3);

    WayPoint *wayPoint5 = new WayPoint(QPoint(445, 100));
    m_wayPointsList.push_back(wayPoint5);
    wayPoint5->setNextWayPoint(wayPoint4);

    WayPoint *wayPoint6 = new WayPoint(QPoint(35, 100));
    m_wayPointsList.push_back(wayPoint6);
    wayPoint6->setNextWayPoint(wayPoint5);
}

void GameWindow::addMyobject(){
    MyObject * object = new MyObject(QPoint(400,100),QPoint(1000,100),":/images/enemy1.png");

    object_list.push_back(object);

    object->move();
    update();
}

void GameWindow::updateScene()
{
   update();
}

