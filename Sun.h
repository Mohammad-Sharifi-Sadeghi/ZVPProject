#ifndef SUN_H
#define SUN_H


#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class Sun : public QObject,  public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Sun(int ,int ,QGraphicsItem* = 0 );
    void mousePressEvent(QGraphicsSceneMouseEvent* );
public slots:
    void destroy();
};

#endif // SUN_H
