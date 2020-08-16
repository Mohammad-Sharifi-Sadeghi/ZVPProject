#include "SunFlower.h"
#include <QTimer>
#include "Sun.h"
#include <stdlib.h>
#include <Game.h>

extern Game* game;

SunFlower::SunFlower(int x, int y, int currentField, QGraphicsItem* parent) : QObject(), QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/sunflower.png"));
    setPos(x, y);
    this->currentField = currentField;
    game->scene->addItem(this);
    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),game,SLOT(sunSpawn()));

    timer->start(15000);
}

void SunFlower::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(game->toBePlacedType == 5){
        game->toBePlacedType = 0;
        game->scene->removeItem(this);
        game->isFieldFull[currentField] = false;
        delete this;
    }
}

