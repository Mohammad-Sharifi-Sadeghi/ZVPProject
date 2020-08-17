#include "Game.h"
#include "Button.h"
#include <QGraphicsTextItem>
#include <stdlib.h> // srand() and rand()
#include <time.h> // time()
#include <QDebug>
#include "Firststage.h"
#include "ShooterPlant.h"
#include <QFont>
#include "Sun.h"
#include "SunFlower.h"
#include <QDebug>
#include "SecondStage.h"
#include "Wallnut.h"
#include "Bomb.h"
#include <QList>
#include "ThirdStage.h"
#include "Plant.h"
#include <QMediaPlayer>



Game::Game(QWidget *parent){
    // set up the screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,750);

    toBePlacedType = 0;
    player = new QMediaPlayer();
    // set up the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,750);
    setScene(scene);

    //TODO save/load operation
    stage = 1;


}

void Game::showMainMenu(){
// create the title text
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Zombies vs Plants"));
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // create the play button
    Button* playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    // create the quit button
    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);
}

void Game::mousePressEvent(QMouseEvent * event){

    //canceling any mouse operations if player right clicks
    if(event->button() == Qt::RightButton){
        toBePlacedType = 0;
    }


    // taking the card
    if(event->x() < 200 && event->x() > 108 && event->y() > 8 && event->y() < 138 && event->button() == Qt::LeftButton && toBePlacedType == 0 && money >= 100){
        toBePlacedType = 1;
    }else if(event->x() < 307 && event->x() > 213 && event->y() > 8 && event->y() < 138 && event->button() == Qt::LeftButton && toBePlacedType == 0 && money >= 50){
        toBePlacedType = 2;
    }else if(event->x() < 396 && event->x() > 308 && event->y() > 8 && event->y() < 138 && event->button() == Qt::LeftButton && toBePlacedType == 0 && money >= 150 && stage > 1){
        toBePlacedType = 3;
    }else if(event->x() < 491 && event->x() > 396 && event->y() > 8 && event->y() < 138 && event->button() == Qt::LeftButton && toBePlacedType == 0 && money >= 150 && stage > 2){
        toBePlacedType = 4;
    }else if(event->x() < 645 && event->x() > 491 && event->y() > 8 && event->y() < 138 && event->button() == Qt::LeftButton && toBePlacedType == 0){
        qDebug() << "taking shovel";
        toBePlacedType = 5;
    }
     //first row placing card section
    for(int i = 0;i < 7;++i){
        if(event->x() > i*100 && event->x() < (i+1)*100 && event->y() > 224 && event->y() < 374 && event->button() == Qt::LeftButton && toBePlacedType != 0 ){
            if(!isFieldFull[i+1]){
                if(toBePlacedType == 1){
                    Plant* sp = new ShooterPlant(i*100,234,i+1);
                    isFieldFull[i+1] = true;
                    toBePlacedType = 0;
                    setMoney(getMoney() - 100);
                    qDebug() << "using shooter";
                }else if(toBePlacedType == 2){
                    Plant* sf = new SunFlower(i*100,234,i+1);
                    isFieldFull[i+1] = true;
                    toBePlacedType = 0;
                    setMoney(getMoney() - 50);
                }
            }
                if(toBePlacedType == 3){
                     qDebug() << "using wallnut";
                     Wallnut* wn = new Wallnut(i*100,234);
                     toBePlacedType = 0;
                     setMoney(getMoney() - 150);
                 }else if(toBePlacedType == 4){
                    Bomb* bomb = new Bomb(i*100,234);
                    toBePlacedType = 0;
                    setMoney(getMoney() - 150);
                }
            break;
        }
    }

    //second row card placement section
    if(stage > 1){
        for(int i = 0;i < 7;++i){
            if(event->x() > i*100 && event->x() < (i+1)*100 && event->y() > 374 && event->y() < 524 && event->button() == Qt::LeftButton && toBePlacedType != 0 ){
                if(!isFieldFull[i+8]){
                    if(toBePlacedType == 1){
                        Plant* sp = new ShooterPlant(i*100,384,i+8);
                        isFieldFull[i+8] = true;
                        toBePlacedType = 0;
                        setMoney(getMoney() - 100);
                    }else if(toBePlacedType == 2){
                        Plant* sf = new SunFlower(i*100,384,i+8);
                        isFieldFull[i+8] = true;
                        toBePlacedType = 0;
                        setMoney(getMoney() - 50);
                    }
                }
                if(toBePlacedType == 3){
                    Wallnut* wn = new Wallnut(i*100,384);
                    toBePlacedType = 0;
                    setMoney(getMoney() - 150);
                }else if(toBePlacedType == 4){
                    Bomb* bomb = new Bomb(i*100,384);
                    toBePlacedType = 0;
                    setMoney(getMoney() - 150);
                }
                break;
            }
        }
    }

    //third row cardplacement section
    if(stage > 2){
        for(int i = 0;i < 7;++i){
            if(event->x() > i*100 && event->x() < (i+1)*100 && event->y() > 524 && event->y() < 674 && event->button() == Qt::LeftButton && toBePlacedType != 0 ){
                if(!isFieldFull[i+15]){
                    if(toBePlacedType == 1){
                        Plant* sp = new ShooterPlant(i*100,534,i+15);
                        isFieldFull[i+15] = true;
                        toBePlacedType = 0;
                        setMoney(getMoney() - 100);
                    }else if(toBePlacedType == 2){
                        Plant* sf = new SunFlower(i*100,534,i+15);
                        isFieldFull[i+15] = true;
                        toBePlacedType = 0;
                        setMoney(getMoney() - 50);
                    }
                }
                if(toBePlacedType == 3){
                    Wallnut* wn = new Wallnut(i*100,534);
                    toBePlacedType = 0;
                    setMoney(getMoney() - 150);
                }else if(toBePlacedType == 4){
                    Bomb* bomb = new Bomb(i*100,534);
                    toBePlacedType = 0;
                    setMoney(getMoney() - 150);
                }
                break;
            }
        }
    }



}

void Game::setMoney(int toBePlaced){
    money = toBePlaced;
    update();
}

int Game::getMoney(){
    return money;
}

void Game::setUpMoneyTextItem(){
    moneyTextItem = new QGraphicsTextItem();
    moneyTextItem->setDefaultTextColor(Qt::black);
    setFont(QFont("times",25));
    scene->addItem(moneyTextItem);
    update();
}

void Game::start(){
    // clear the screen
    scene->clear();
    // set up money
    money = 0;
    //clearing the fields
    for(int i = 0;i < 22;++i){
        isFieldFull[i] = false;
    }
    if(stage == 1){
        FirstStage* fs = new FirstStage();
    }else if(stage == 2){
        SecondStage* ss = new SecondStage(part);
    }else if(stage == 3){
        ThirdStage* ts = new ThirdStage(part);
    }
}

void Game::sunSpawn(){

    int x = rand()%600 + 100;
    int y = rand()%500 + 75;

    Sun* sun = new Sun(x, y);
    scene->addItem(sun);
}

void Game::update(){
    moneyTextItem->setPlainText(QString::number(money));
    moneyTextItem->setPos(50 - moneyTextItem->boundingRect().width() / 2,105);
}

void Game::showVictory(){
// create the title text

    player->setMedia(QUrl("qrc:/musics/stageVictory.ogg"));
    player->play();
    scene->setBackgroundBrush(QBrush(QImage(":/images/stagevictory.png")));
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Victory !!!"));
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // create the play button
    Button* playButton = new Button(QString("Continue"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    // create the quit button
    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);




}

void Game::showDefeated(){
    player->setMedia(QUrl("qrc:/musics/stageDefeat.ogg"));
    player->play();
    scene->clear();
    scene->setBackgroundBrush(QBrush(QImage(":/images/defeat.png")));
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("DEFEATED !!!"));
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // create the play button
    Button* playButton = new Button(QString("Try Again"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    // create the quit button
    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);

}

void Game::showEnd(){
    scene->setBackgroundBrush(QBrush(QImage(":/images/theend.png")));
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("The End"));
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);



    // create the quit button
    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);

}
