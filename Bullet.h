#ifndef BULLET_H
#define BULLET_H


#include <QGraphicsPixmapItem>
#include <QObject>

class Bullet : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Bullet(int, int, int, QGraphicsItem* = 0);
public slots:
    void move();
private:
    int fps;


};
#endif // BULLET_H
