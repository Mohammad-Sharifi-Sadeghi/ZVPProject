#ifndef FIRSTSTAGE_H
#define FIRSTSTAGE_H



#include <QObject>
#include <QMouseEvent>
#include <QMediaPlayer>
#include <QString>


class FirstStage : public QObject{
    Q_OBJECT
public:
    FirstStage();
    void mouseMoveEvent(QMouseEvent*);

public slots:
    void timeCounter();
    void defeat();
private:
    bool isPlacing;
    QMediaPlayer* backGroundMusic;
    int second;

};

#endif // FIRSTSTAGE_H
