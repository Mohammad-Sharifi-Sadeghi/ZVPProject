#ifndef SUNFLOWER_H
#define SUNFLOWER_H


#include <QObject>
#include <QGraphicsPixmapItem>

#include <QGraphicsSceneMouseEvent>

class SunFlower : public QObject, public QGraphicsPixmapItem{
        Q_OBJECT
public:
    SunFlower(int, int, int, QGraphicsItem* = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    int currentField;

};

#endif // SUNFLOWER_H
