#ifndef SHOOTERPLANT_H
#define SHOOTERPLANT_H


#include <QGraphicsPixmapItem>
#include <QObject>

#include <QGraphicsSceneMouseEvent>

class ShooterPlant : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    ShooterPlant(int , int , int, int, QGraphicsItem* = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent*);


    int currentField;
public slots:
    void shoot();
private:
    int bulletFps;

};

#endif // SHOOTERPLANT_H
