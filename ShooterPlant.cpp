#include "ShooterPlant.h"
#include <QTimer>
#include "Bullet.h"
#include "Game.h"
#include <QDebug>

extern Game* game;

ShooterPlant::ShooterPlant(int x, int y, int bulletFps, int currentField, QGraphicsItem* parent):QObject(), QGraphicsPixmapItem(parent) {
    setPixmap(QPixmap(":/images/shooterplant.png"));
    setPos(x, y);

    this->currentField = currentField;
    this->bulletFps = bulletFps;
    game->scene->addItem(this);
    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(shoot()));
    timer->start(1000);
}

void ShooterPlant::mousePressEvent(QGraphicsSceneMouseEvent *){
    if(game->toBePlacedType == 5){
        game->toBePlacedType = 0;
        game->scene->removeItem(this);
        game->isFieldFull[currentField] = false;
        delete this;
    }
}

void ShooterPlant::shoot(){
    Bullet* bullet = new Bullet(95, 0,bulletFps,this);
    game->scene->addItem(bullet);
}
