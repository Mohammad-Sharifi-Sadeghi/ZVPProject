#include "Sun.h"
#include <QTimer>
#include "Game.h"
#include <QDebug>

extern Game* game;
Sun::Sun(int x, int y, QGraphicsItem* parent) : QObject(), QGraphicsPixmapItem(parent){
    setPos(x, y);
    setPixmap(QPixmap(":/images/sun.png"));

    QTimer* timer = new QTimer(this);
    timer->singleShot(2000,this,SLOT(destroy()));

}

void Sun::mousePressEvent(QGraphicsSceneMouseEvent * event){
    game->setMoney(game->getMoney() + 25);
    game->scene->removeItem(this);
    delete this;
}

void Sun::destroy(){
    game->scene->removeItem(this);
    delete this;
}
