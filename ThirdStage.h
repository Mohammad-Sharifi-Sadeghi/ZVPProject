#ifndef THIRDSTAGE_H
#define THIRDSTAGE_H


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
};

#endif // THIRDSTAGE_H
