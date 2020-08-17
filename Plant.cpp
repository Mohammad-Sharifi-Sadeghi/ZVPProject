#include "Plant.h"
#include "Game.h"

extern Game* game;

Plant::Plant(int x, int y,int currentField, QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent){
    setPos(x,y);
    this->currentField = currentField;
    game->scene->addItem(this);
}

void Plant::mousePressEvent(QGraphicsSceneMouseEvent *){
    if(game->toBePlacedType == 5){
        game->toBePlacedType = 0;
        game->scene->removeItem(this);
        game->isFieldFull[currentField] = false;
        delete this;
    }
}
