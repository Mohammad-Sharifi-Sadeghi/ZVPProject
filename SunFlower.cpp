#include "SunFlower.h"
#include <QTimer>
#include "Sun.h"
#include <stdlib.h>
#include <Game.h>

extern Game* game;

SunFlower::SunFlower(int x, int y, int currentField, QGraphicsItem* parent) : Plant(x,y,currentField,parent){
    setPixmap(QPixmap(":/images/sunflower.png"));

    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),game,SLOT(sunSpawn()));

    timer->start(15000);
}


