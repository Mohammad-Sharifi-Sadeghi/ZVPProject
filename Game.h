#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsWidget>
#include <QMediaPlayer>
#include "Plant.h"


class Game : public QGraphicsView{
    Q_OBJECT
public:

    Game(QWidget* = NULL);
    void showMainMenu();
    void showVictory();
    void showDefeated();
    void showEnd();
    int gameStage;
    void mousePressEvent(QMouseEvent*);
    void setMoney(int );
    int getMoney();
    void setUpMoneyTextItem();
    void setPart(int );
    void partStartingPlantsLoad();


    int stage;
    int part;
    int toBePlacedType; //0 = null, 1 = shooter , 2 = sunflower , 3 = hover , 4 = bomb , 5 = delete
    bool isFieldFull[21];
    QGraphicsScene* scene;
    QMap<int,Plant*> fieldPlant;
public slots:
    void start();
    void sunSpawn();
private:


    int money;
    QMediaPlayer* victoryPlayer;
    QMediaPlayer* defeatPlayer;
    QGraphicsTextItem* moneyTextItem;
    void update();
};

#endif // GAME_H
