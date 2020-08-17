#ifndef PLANT_H
#define PLANT_H

#include <QObject>
#include <QGraphicsPixmapItem>
class Plant : public QObject, public QGraphicsPixmapItem{

    Q_OBJECT
public:
    explicit Plant(int , int ,int ,QGraphicsItem *parent = nullptr);
    void mousePressEvent(QGraphicsSceneMouseEvent*);

    int currentField;
signals:
private:


};

#endif // PLANT_H
