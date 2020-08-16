#include "Firststage.h"
#include "Game.h"
#include <QImage>
#include <QBrush>
#include <QGraphicsScene>
#include <QTimer>
#include "Zombie.h"
#include "ShooterPlant.h"
#include <QGraphicsView>
#include <QDebug>
#include <QPointF>
#include <QLineF>

extern Game* game;

FirstStage::FirstStage(){
    second = 0;

    game->setUpMoneyTextItem();
    game->scene->setBackgroundBrush(QBrush(QImage(":/images/firstStage.png")));

    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeCounter()));

    timer->start(1000);

    //sun spawning
    QTimer* sunSpawnTimer = new QTimer(this);
    connect(sunSpawnTimer,SIGNAL(timeout()),game,SLOT(sunSpawn()));

    sunSpawnTimer->start(10000);
}




void FirstStage::timeCounter(){
    second++;
    if(second == 50){
        Zombie* zombie = new Zombie(800,234,1,4,false);
        connect(zombie,SIGNAL(endReached()),this,SLOT(defeat()));
        game->scene->addItem(zombie);
    }else if(second == 5){
        Zombie* zombie = new Zombie(800,234,1,4,false);
         connect(zombie,SIGNAL(endReached()),this,SLOT(defeat()));
        game->scene->addItem(zombie);
    }else if(second == 6){
        Zombie* zombie = new Zombie(800,234,1,4,false);
         connect(zombie,SIGNAL(endReached()),this,SLOT(defeat()));
        game->scene->addItem(zombie);
    }else if(second == 7){
        Zombie* zombie = new Zombie(800,234,1,4,false);
         connect(zombie,SIGNAL(endReached()),this,SLOT(defeat()));
        game->scene->addItem(zombie);
    }else if(second == 60){
        Zombie* zombie = new Zombie(800,234,1,4,false);
         connect(zombie,SIGNAL(endReached()),this,SLOT(defeat()));
        game->scene->addItem(zombie);
    }else if(second == 72){
        game->stage = 2;
        game->part = 1;
        game->scene->clear();
        game->showVictory();
        delete this;
    }
}

void FirstStage::defeat(){
    game->toBePlacedType = 0;
    qDebug() << "second line";
    game->showDefeated();
    qDebug() << "third line";
    delete this;
}

