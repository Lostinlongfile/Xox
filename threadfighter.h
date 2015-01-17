#ifndef THREADFIGHTER_H
#define THREADFIGHTER_H

#include <QThread>
#include "Xox_console/base_player.h"
#include "Xox_console/matrix.h"
class ThreadFighter : public QThread
{
    Q_OBJECT
public:
    base_player *P1,*P2;
    void init( base_player *P_1,base_player*P_2,int _all,int mini=-1);
    int all,minim,cminim,lminim;

    Matrix world;
    explicit ThreadFighter(QObject *parent = 0);
protected:
    void run();
signals:
    void P1_win();
    void P2_win();
    void finded();
public slots:
    
};

#endif // THREADFIGHTER_H
