#include "Bullet.h"
#include <QTimer>
#include <QList>
#include <QGraphicsItem>
#include "Zombie.h"
#include "Game.h"

extern Game* game;
Bullet::Bullet(int x, int y, int fps, QGraphicsItem* parent) : QObject() , QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/bullet.png"));
    setPos(x, y);
    this->fps = fps;
    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Bullet::move(){
    QList<QGraphicsItem*> colliding_items = collidingItems();

    for(int i = 0;i < colliding_items.size();++i){
        if(typeid (*(colliding_items[i])) == typeid (Zombie)){
            static_cast<Zombie*>(colliding_items[i])->decrease();
            game->scene->removeItem(this);
            delete this;
            return;
        }
    }
    if(x() > 800){
        game->scene->removeItem(this);
        delete this;
        return;
    }

    setPos(x() + 5*fps, y());

}
