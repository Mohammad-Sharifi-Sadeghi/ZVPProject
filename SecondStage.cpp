#include "SecondStage.h"
#include <QTimer>
#include <stdlib.h>
#include "Game.h"
#include <Zombie.h>
#include <QDebug>
#include "PartVictory.h"

extern Game* game;

SecondStage::SecondStage(int part){
    qDebug() << part;
    second = 0;
    this->part = part;
    dice();
    game->setUpMoneyTextItem();
    game->scene->setBackgroundBrush(QBrush(QImage(":/images/secondStage.png")));
    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeCounter()));
    timer->start(1000);

    QTimer* sunSpawnerTimer = new QTimer(this);
    connect(sunSpawnerTimer,SIGNAL(timeout()),game,SLOT(sunSpawn()));
    sunSpawnerTimer->start(10000);
}

void SecondStage::timeCounter(){

    second++;
    if(part == 1){
        if(second == 50){
            Zombie* zombie = new Zombie(800,firstRow,1,4,false);
            connect(zombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(zombie);
        }else if(second == 55){
            Zombie* zombie = new Zombie(800,secondRow,1,4,false);
            connect(zombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(zombie);
        }else if(second == 58){
            Zombie* zombie = new Zombie(800,firstRow,1,4,false);
            connect(zombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(zombie);
        }else if(second == 60){
            Zombie* zombie = new Zombie(800,secondRow,1,4,false);
            connect(zombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(zombie);
        }else if(second == 62){
            Zombie* zombie = new Zombie(800,firstRow,1,4,false);
            connect(zombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(zombie);
        }else if(second == 63){
            Zombie* firstZombie = new Zombie(800,firstRow,1,4,false);
            connect(firstZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(firstZombie);
            Zombie* secondZombie = new Zombie(800,secondRow,1,4,false);
             connect(secondZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(secondZombie);
        }else if(second == 64){
            Zombie* zombie = new Zombie(800,secondRow,1,4,false);
            connect(zombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(zombie);
        }else if(second == 76){
            PartVictory* pv = new PartVictory();
            game->part = 2;
            part = 2;
            second = 0;

        }
    }else if(part == 2){
        qDebug() << second;
        if(second == 45){
            Zombie* zombie = new Zombie(800,firstRow,1,4,false);
            connect(zombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(zombie);
        }else if(second == 48){
            Zombie* firstZombie = new Zombie(800,firstRow,1,4,false);
            connect(firstZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(firstZombie);
            Zombie* secondZombie = new Zombie(800,secondRow,1,4,false);
            connect(secondZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(secondZombie);
        }else if(second == 49){
            Zombie* zombie = new Zombie(800,firstRow,1,4,false);
            connect(zombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(zombie);
        }else if(second == 50){
            Zombie* firstZombie = new Zombie(800,firstRow,1,4,false);
            connect(firstZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(firstZombie);
            Zombie* secondZombie = new Zombie(800,secondRow,1,4,false);
            connect(secondZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(secondZombie);
        }else if(second == 51){
            Zombie* firstZombie = new Zombie(800,firstRow,1,4,false);
            connect(firstZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(firstZombie);
            Zombie* secondZombie = new Zombie(800,secondRow,1,4,false);
            connect(secondZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(secondZombie);
        }else if(second == 52){
            Zombie* firstZombie = new Zombie(800,firstRow,1,4,false);
            connect(firstZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(firstZombie);
            Zombie* secondZombie = new Zombie(800,secondRow,1,4,false);
            connect(secondZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(secondZombie);
        }else if(second == 64){
            game->stage = 3;
            game->part = 1;
            game->scene->clear();
            game->showVictory();
            delete this;
        }
    }
}

void SecondStage::showPartVictory(){

}

void SecondStage::defeat(){
    game->showDefeated();
    game->toBePlacedType = 0;
    qDebug() << "first line";
    game->scene->clear();
    qDebug() << "second line";

    qDebug() << "third line";
    delete this;
}

void SecondStage::dice(){
    int x = rand()/RAND_MAX;
    if(x > 0.5){
        firstRow = 234;
        secondRow = 384;
    }else{
        firstRow = 384;
        secondRow = 234;
    }
}
