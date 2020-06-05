#include "chooselevelwindow.h"
#include "mybutton.h"
#include "gamewindow.h"
#include <QPainter>
#include <QTimer>
#include <QPushButton>
ChooseLevelWindow::ChooseLevelWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(1500,1200);

    MyButton * back_bin = new MyButton(":/images/back-button.png");
    back_bin->setParent(this);
    back_bin->setIconSize(QSize(350,175));
    back_bin->move(-100,900);

//    MyButton * play = new MyButton(":/images/Button.png");
//    play->setParent(this);
//    play->move(1100,1010);

//    connect(play,&MyButton::clicked,this,&ChooseLevelWindow::addMyobject);

    connect(back_bin,&MyButton::clicked,this,[=](){
        emit chooseBack();
    });

    //设置关卡按钮
    MyButton * levelbtn1 = new MyButton(":/images/levelbtn1.png");
    levelbtn1->setParent(this);
    levelbtn1->setIconSize(QSize(200,200));
    levelbtn1->move(400,300);

    MyButton * levelbtn2 = new MyButton(":/images/levelbtn2.png");
    levelbtn2->setParent(this);
    levelbtn2->setIconSize(QSize(200,200));
    levelbtn2->move(700,300);

    MyButton * levelbtn3 = new MyButton(":/images/levelbtn3.png");
    levelbtn3->setParent(this);
    levelbtn3->setIconSize(QSize(200,200));
    levelbtn3->move(1000,300);

    MyButton * levelbtn4 = new MyButton(":/images/levelbtn4.png");
    levelbtn4->setParent(this);
    levelbtn4->setIconSize(QSize(200,200));
    levelbtn4->move(200,600);

    MyButton * levelbtn5 = new MyButton(":/images/levelbtn5.png");
    levelbtn5->setParent(this);
    levelbtn5->setIconSize(QSize(200,200));
    levelbtn5->move(500,600);

    MyButton * levelbtn6 = new MyButton(":/images/levelbtn6.png");
    levelbtn6->setParent(this);
    levelbtn6->setIconSize(QSize(200,200));
    levelbtn6->move(800,600);

    //点击关卡，显示对应主题游戏界面
    GameWindow * scene1 = new GameWindow(1);
    connect(levelbtn1,&MyButton::clicked,[=](){
        this->hide();
        scene1->show();
    });
    GameWindow * scene2 = new GameWindow(2);
    connect(levelbtn2,&MyButton::clicked,[=](){
        this->hide();
        scene2->show();
    });
    GameWindow * scene3 = new GameWindow(3);
    connect(levelbtn3,&MyButton::clicked,[=](){
        this->hide();
        scene3->show();
    });
    GameWindow * scene4 = new GameWindow(4);
    connect(levelbtn4,&MyButton::clicked,[=](){
        this->hide();
        scene4->show();
    });

    //点击返回按钮，返回选择关卡界面
    connect(scene1,&GameWindow::chooseBack,this,[=](){
        scene1->hide();
        this->show();
    });

    connect(scene2,&GameWindow::chooseBack,this,[=](){
        scene2->hide();
        this->show();
    });

    connect(scene3,&GameWindow::chooseBack,this,[=](){
        scene3->hide();
        this->show();
    });

    connect(scene4,&GameWindow::chooseBack,this,[=](){
        scene4->hide();
        this->show();
    });




    QTimer * timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&ChooseLevelWindow::updateScene);
    timer->start(10);

}

void ChooseLevelWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pixmap(":/images/Bg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);


//    foreach(Tower * tower,tower_list)
//        tower->draw(&painter);
//    foreach(MyObject * object,object_list)
//        object->draw(&painter);


}



//void ChooseLevelWindow::addMyobject(){
//    MyObject * object = new MyObject(QPoint(400,100),QPoint(1000,100),":/images/enemy1.png");
//    object_list.push_back(object);

//    object->move();
//    update();
//}

void ChooseLevelWindow::updateScene()
{
   update();
}
