#ifndef WALLNUT_H
#define WALLNUT_H


#include <QObject>
#include <QGraphicsPixmapItem>

class Wallnut : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Wallnut(int ,int ,QGraphicsItem* = 0);
public slots:
    void move();
};

#endif // WALLNUT_H
