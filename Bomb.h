#ifndef BOMB_H
#define BOMB_H


#include <QObject>
#include <QGraphicsPixmapItem>


class Bomb : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Bomb(int, int, QGraphicsItem* = 0);
public slots:
    void explode();
private:
    QGraphicsRectItem* attack_area;
};

#endif // BOMB_H
