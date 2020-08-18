#ifndef SHOOTERPLANT_H
#define SHOOTERPLANT_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include "Plant.h"
#include <QGraphicsSceneMouseEvent>

class ShooterPlant : public Plant{
    Q_OBJECT
public:
    ShooterPlant(int , int , int, QGraphicsItem* = 0);




public slots:
    void shoot();
private:
    int bulletFps;

};

#endif // SHOOTERPLANT_H
