#ifndef THIRDSTAGE_H
#define THIRDSTAGE_H

#include <QMediaPlayer>
#include <QObject>


class ThirdStage : public QObject{
    Q_OBJECT
public:
    ThirdStage(int );
public slots:
    void timeCounter();
    void defeat();
private:
    void dice();
    int firstRow, secondRow, thirdRow, second, part;
    QMediaPlayer* backGroundMusic;
};

#endif // THIRDSTAGE_H
