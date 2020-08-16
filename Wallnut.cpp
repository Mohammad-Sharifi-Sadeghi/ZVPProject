#include "Wallnut.h"
#include <QTimer>
#include "Game.h"
#include <QList>
#include "Zombie.h"

extern Game* game;

Wallnut::Wallnut(int x, int y, QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/wallnut.png"));
    setPos(x , y);
    game->scene->addItem(this);
    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(100);

}

void Wallnut::move(){
    QList<QGraphicsItem*> colliding_items = collidingItems();
    if(x() > 800){
        game->scene->removeItem(this);
        delete this;
        return;
    }
    for(int i = 0;i < colliding_items.size();++i){
        if(typeid (*(colliding_items[i]))== typeid (Zombie)){
            game->scene->removeItem(colliding_items[i]);
            delete colliding_items[i];
        }
    }

    setPos(x() + 8, y());
}
