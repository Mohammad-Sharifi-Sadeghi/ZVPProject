#include "Bomb.h"
#include "Game.h"
#include <QTimer>
#include <QList>
#include "Zombie.h"
#include "QPointF"
#include <QDebug>
#include <QRectF>

extern Game* game;

Bomb::Bomb(int x, int y, QGraphicsItem* parent):QObject(), QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/bomb.png"));
    setPos(x, y);
    //QPointF attack_area_Point = mapToScene(0,0);
    //qDebug() << attack_area_Point.x() << "     " << attack_area_Point.y();
    attack_area = new QGraphicsRectItem(this);
    attack_area->setPos(-100,-150);
    attack_area->setRect(0 ,0,300,450);



    game->scene->addItem(this);
    QTimer::singleShot(2000,this,SLOT(explode()));

}

void Bomb::explode(){
    QList<QGraphicsItem*> colliding_items = attack_area->collidingItems();
    qDebug() << attack_area;
    for(int i = 0;i < colliding_items.size();++i){
        if(typeid (*(colliding_items[i])) == typeid (Zombie)){
            game->scene->removeItem(colliding_items[i]);
            delete colliding_items[i];
        }
    }
    delete this;
}
