#include "ThirdStage.h"
#include <QTimer>
#include "Game.h"
#include "Zombie.h"
#include <stdlib.h>
#include <QDebug>
#include "PartVictory.h"

extern Game* game;

ThirdStage::ThirdStage(){

    part = 1;
    second = 0;

    dice();

    game->setUpMoneyTextItem();
    game->scene->setBackgroundBrush(QBrush(QImage(":/images/thirdStage.png")));

    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeCounter()));
    timer->start(1000);

    QTimer* sunSpawnTimer = new QTimer(this);
    connect(sunSpawnTimer,SIGNAL(timeout()),game,SLOT(sunSpawn()));
    sunSpawnTimer->start(10000);
    backGroundMusic = new QMediaPlayer(this);
    backGroundMusic->setMedia(QUrl("qrc:/musics/bgmusic.mp3"));
    backGroundMusic->play();
    backGroundMusic->setVolume(20);

}

void ThirdStage::timeCounter(){
    second++;

    if(part == 1){
        if(second == 40){
            Zombie* zombie = new Zombie(800,firstRow,1,4,false);
            connect(zombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(zombie);
        }else if(second == 44){
            Zombie* zombie = new Zombie(800,secondRow,1,4,false);
            connect(zombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(zombie);
        }else if(second == 46){
            Zombie* zombie = new Zombie(800,thirdRow,1,4,false);
            connect(zombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(zombie);
        }else if(second == 47){
            Zombie* firstZombie = new Zombie(800,firstRow,1,4,false);
            connect(firstZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(firstZombie);
            Zombie* secondZombie = new Zombie(800,secondRow,1,4,false);
            connect(secondZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(secondZombie);
        }else if(second == 48){
            Zombie* firstZombie = new Zombie(800,thirdRow,1,4,false);
            connect(firstZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(firstZombie);
            Zombie* secondZombie = new Zombie(800,firstRow,1,4,false);
            connect(secondZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(secondZombie);
        }else if(second == 50){
            Zombie* firstZombie = new Zombie(800,secondRow,1,4,false);
            connect(firstZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(firstZombie);
            Zombie* secondZombie = new Zombie(800,thirdRow,1,4,false);
            connect(secondZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(secondZombie);
            Zombie* thirdZombie = new Zombie(800,firstRow,1,4,false);
            connect(thirdZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(thirdZombie);
        }else if(second == 51){
            Zombie* firstZombie = new Zombie(800,secondRow,1,4,false);
            connect(firstZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(firstZombie);

            Zombie* secondZombie = new Zombie(800,thirdRow,1,4,false);
            connect(secondZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(secondZombie);
        }else if(second == 53){
            Zombie* firstZombie = new Zombie(800,firstRow,1,10,true);
            connect(firstZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(firstZombie);

            Zombie* secondZombie = new Zombie(800,secondRow,1,10,true);
            connect(secondZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(secondZombie);

            Zombie* thirdZombie = new Zombie(800,thirdRow,1,10,true);
            connect(thirdZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(thirdZombie);
        }else if(second == 67){
            PartVictory* pv = new PartVictory();
            backGroundMusic->setPosition(0);
            part = 2;
            second = 0;
            game->part = 2;
        }
    }else if(part == 2){
        if(second == 40){
            Zombie* zombie = new Zombie(800,firstRow,1,4,false);
            connect(zombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(zombie);
        }else if(second == 44){
            Zombie* zombie = new Zombie(800,secondRow,1,4,false);
            connect(zombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(zombie);
        }else if(second == 46){
            Zombie* zombie = new Zombie(800,thirdRow,1,4,false);
            connect(zombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(zombie);
        }else if(second == 47){
            Zombie* firstZombie = new Zombie(800,firstRow,1,4,false);
            connect(firstZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(firstZombie);
            Zombie* secondZombie = new Zombie(800,secondRow,1,4,false);
            connect(secondZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(secondZombie);
        }else if(second == 48){
            Zombie* firstZombie = new Zombie(800,thirdRow,1,4,false);
            connect(firstZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(firstZombie);
            Zombie* secondZombie = new Zombie(800,firstRow,1,4,false);
            connect(secondZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(secondZombie);
        }else if(second == 50){
            Zombie* firstZombie = new Zombie(800,secondRow,1,4,false);
            connect(firstZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(firstZombie);
            Zombie* secondZombie = new Zombie(800,thirdRow,1,4,false);
            connect(secondZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(secondZombie);
            Zombie* thirdZombie = new Zombie(800,firstRow,1,4,false);
            connect(thirdZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(thirdZombie);
        }else if(second == 51){
            Zombie* firstZombie = new Zombie(800,secondRow,1,4,false);
            connect(firstZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(firstZombie);
            Zombie* secondZombie = new Zombie(800,thirdRow,1,4,false);
            connect(secondZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(secondZombie);
        }else if(second == 53){
            Zombie* firstZombie = new Zombie(800,firstRow,1,12,true);
            connect(firstZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(firstZombie);
            Zombie* secondZombie = new Zombie(800,secondRow,1,12,true);
            connect(secondZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(secondZombie);
            Zombie* thirdZombie = new Zombie(800,thirdRow,1,12,true);
            connect(thirdZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(thirdZombie);
        }else if(second == 67){
            PartVictory* pv = new PartVictory();
            backGroundMusic->setPosition(0);
            part = 3;
            game->part = 3;
            second = 0;
        }
    }else if(part == 3){
        if(second == 40){
            Zombie* zombie = new Zombie(800,firstRow,2,15,true);
            connect(zombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(zombie);
        }else if(second == 44){
            Zombie* zombie = new Zombie(800,secondRow,2,15,true);
            connect(zombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(zombie);
        }else if(second == 46){
            Zombie* zombie = new Zombie(800,thirdRow,2,15,true);
            connect(zombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(zombie);
        }else if(second == 47){
            Zombie* firstZombie = new Zombie(800,firstRow,2,15,true);
            connect(firstZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(firstZombie);
            Zombie* secondZombie = new Zombie(800,secondRow,2,15,true);
            connect(secondZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(secondZombie);
        }else if(second == 48){
            Zombie* firstZombie = new Zombie(800,thirdRow,2,15,true);
            connect(firstZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(firstZombie);
            Zombie* secondZombie = new Zombie(800,firstRow,2,15,true);
            connect(secondZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(secondZombie);
        }else if(second == 50){
            Zombie* firstZombie = new Zombie(800,secondRow,2,15,true);
            connect(firstZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(firstZombie);
            Zombie* secondZombie = new Zombie(800,thirdRow,2,15,true);
            connect(secondZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(secondZombie);
            Zombie* thirdZombie = new Zombie(800,firstRow,2,15,true);
            connect(thirdZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(thirdZombie);
        }else if(second == 51){
            Zombie* firstZombie = new Zombie(800,secondRow,2,15,true);
            connect(firstZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(firstZombie);
            Zombie* secondZombie = new Zombie(800,thirdRow,2,15,true);
            connect(secondZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(secondZombie);
        }else if(second == 53){
            Zombie* firstZombie = new Zombie(800,firstRow,2,15,true);
            connect(firstZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(firstZombie);
            Zombie* secondZombie = new Zombie(800,secondRow,2,15,true);
            connect(secondZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(secondZombie);
            Zombie* thirdZombie = new Zombie(800,thirdRow,2,15,true);
            connect(thirdZombie,SIGNAL(endReached()),this,SLOT(defeat()));
            game->scene->addItem(thirdZombie);
        }else if(second == 63){

            game->scene->clear();
            game->showEnd();
        }
    }
}

void ThirdStage::defeat(){

    game->toBePlacedType = 0;    
    game->scene->clear();   
    game->showDefeated();

    delete this;
}

void ThirdStage::dice(){

    double x = (double)rand()/RAND_MAX * 3/2;
    double y = (double)rand()/RAND_MAX;
    if(x < 0.5){
        firstRow = 234;
        if(y < 0.5){
            secondRow = 384;
            thirdRow = 534;
        }else{
            secondRow = 534;
            thirdRow = 384;
        }
    }else if(x > 1){
        firstRow = 534;
        if(y < 0.5){
            secondRow = 234;
            thirdRow = 384;
        }else{
            secondRow = 384;
            thirdRow = 234;
        }
    }else{
        secondRow = 384;
        if(y < 0.5){
            firstRow = 234;
            thirdRow = 384;
        }else{
            firstRow = 384;
            thirdRow = 234;
        }
    }
}
