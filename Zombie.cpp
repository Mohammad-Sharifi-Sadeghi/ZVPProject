#include "Zombie.h"
#include <QTimer>
#include <QList>
#include "Game.h"
#include <QDebug>
#include "ShooterPlant.h"
#include "sunflower.h"

extern Game* game;

Zombie::Zombie(int x, int y, int fps, int health, bool isBoss, QGraphicsItem* parent): QObject() , QGraphicsPixmapItem(parent){
    setPos(x, y);
    if(isBoss){
        setPixmap(QPixmap(":/images/zombieBoss.png"));
    }else{
        setPixmap(QPixmap(":/images/zombie.png"));
    }
    this->fps = fps;
    this->health = health;

    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Zombie::decrease(){
    if(this->health == 1){
        game->scene->removeItem(this);
        delete this;
    }else{
        health--;
    }
}

void Zombie::move(){
    QList<QGraphicsItem*> colliding_items = this->collidingItems();
    if(x() == 0){
        emit endReached();
        return;
    }
    for(int i = 0;i < colliding_items.size();++i){
        if(typeid(*(colliding_items[i])) == typeid (ShooterPlant)){
            game->isFieldFull[static_cast<ShooterPlant*>(colliding_items[i])->currentField] = false;
            game->scene->removeItem(colliding_items[i]);
            delete colliding_items[i];
            qDebug() << "destroying plant";
        }else if(typeid(*(colliding_items[i])) == typeid (SunFlower)){
            game->isFieldFull[static_cast<SunFlower*>(colliding_items[i])->currentField] = false;
            game->scene->removeItem(colliding_items[i]);
            delete colliding_items[i];
            qDebug() << "destroying plant";
        }
    }
    setPos(x() - 5,y());
}
