#include "Zombie.h"
#include <QTimer>
#include <QList>
#include "Game.h"
#include <QDebug>
#include "ShooterPlant.h"
#include "SunFlower.h"
#include <QMediaPlayer>
#include "Bomb.h"

extern Game* game;

Zombie::Zombie(int x, int y, int fps, int health, bool isBoss, QGraphicsItem* parent): QObject() , QGraphicsPixmapItem(parent){
    setPos(x, y);
    QMediaPlayer* groanPlayer = new QMediaPlayer(this);
    zombieBitePlayer = new QMediaPlayer(this);
    zombieBitePlayer->setMedia(QUrl("qrc:/musics/zombieBite.ogg"));

    if(isBoss){
        setPixmap(QPixmap(":/images/zombieBoss.png"));
        groanPlayer->setMedia(QUrl("qrc:/musics/zombieBossGroan.ogg"));
    }else{
        setPixmap(QPixmap(":/images/zombie.png"));
        groanPlayer->setMedia(QUrl("qrc:/musics/zombieGroan.ogg"));
    }
    groanPlayer->play();
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

            if(zombieBitePlayer->state()== QMediaPlayer::PlayingState){
                zombieBitePlayer->setPosition(0);

            }else if(zombieBitePlayer->state() == QMediaPlayer::StoppedState){
                zombieBitePlayer->play();

            }
            game->isFieldFull[static_cast<ShooterPlant*>(colliding_items[i])->currentField] = false;
            game->scene->removeItem(colliding_items[i]);
            delete colliding_items[i];

        }else if(typeid(*(colliding_items[i])) == typeid (SunFlower)){
            if(zombieBitePlayer->state()== QMediaPlayer::PlayingState){
                zombieBitePlayer->setPosition(0);
            }if(zombieBitePlayer->state() == QMediaPlayer::StoppedState){
                zombieBitePlayer->play();
            }
            game->isFieldFull[static_cast<SunFlower*>(colliding_items[i])->currentField] = false;
            game->scene->removeItem(colliding_items[i]);
            delete colliding_items[i];

        }
    }
    setPos(x() - 5*fps,y());
}
