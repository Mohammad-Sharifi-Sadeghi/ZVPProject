#include "PartVictory.h"
#include "Game.h"
#include <QTimer>

extern Game* game;

PartVictory::PartVictory(){
    setPixmap(QPixmap(":/images/nextround.png"));
    setPos(276,300);
    game->scene->addItem(this);
    QTimer::singleShot(2000,this,SLOT(destroy()));
}

void PartVictory::destroy(){
    game->scene->removeItem(this);
    delete this;
}
