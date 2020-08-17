#ifndef ZOMBIE_H
#define ZOMBIE_H


#include <QObject>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>

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
    QMediaPlayer* zombieBitePlayer;
};

#endif // ZOMBIE_H
