#ifndef ZOMBIE_H
#define ZOMBIE_H


#include <QObject>
#include <QGraphicsPixmapItem>

class Zombie : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Zombie(int , int , int , int , bool, QGraphicsItem* = 0);
    void decrease();
signals:
    void endReached();
public slots:
    void move();
private:
    int fps, health;
};

#endif // ZOMBIE_H
