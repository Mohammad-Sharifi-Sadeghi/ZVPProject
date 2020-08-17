#ifndef SUNFLOWER_H
#define SUNFLOWER_H


#include <QObject>
#include <QGraphicsPixmapItem>
#include "Plant.h"

#include <QGraphicsSceneMouseEvent>

class SunFlower : public Plant{
        Q_OBJECT
public:
    SunFlower(int, int, int, QGraphicsItem* = 0);
    int currentField;

};

#endif // SUNFLOWER_H
