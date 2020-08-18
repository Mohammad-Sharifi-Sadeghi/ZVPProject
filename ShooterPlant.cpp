#include "ShooterPlant.h"
#include <QTimer>
#include "Bullet.h"
#include "Game.h"
#include <QDebug>

extern Game* game;

ShooterPlant::ShooterPlant(int x, int y, int currentField, QGraphicsItem* parent):Plant(x,y,currentField,parent){
    setPixmap(QPixmap(":/images/shooterplant.png"));
    if(game->stage == 3 && game->part == 3){
        this->bulletFps = 3;
    }else{
        this->bulletFps = 1;
    }


    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(shoot()));
    timer->start(500);
}


void ShooterPlant::shoot(){
    Bullet* bullet = new Bullet(95, 0,bulletFps,this);
    game->scene->addItem(bullet);
}
