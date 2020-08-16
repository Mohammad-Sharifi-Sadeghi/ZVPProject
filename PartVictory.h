#ifndef PARTVICTORY_H
#define PARTVICTORY_H
#include <QObject>
#include <QGraphicsPixmapItem>

class PartVictory : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    PartVictory();
public slots:
    void destroy();
};


#endif // PARTVICTORY_H
