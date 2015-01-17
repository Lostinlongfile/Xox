#include "threadfighter.h"

ThreadFighter::ThreadFighter(QObject *parent) :
    QThread(parent)
{

}
void ThreadFighter::init(base_player *P_1, base_player *P_2, int _all,int mini)
{
P1=(P_1),P2=(P_2),all=(_all);
minim=mini;cminim=0;
}
void ThreadFighter::run()
{
    int mi=10000;

    for(int i=0; i<all; i++)
    {
        world.clear();
        P1->refresh();
        P2->refresh();
        world.set_X(P1);
        world.set_O(P2);
        int stp=-1;
        while(true)
        {
            stp++;
            world.do_step_1();
            if(world.win())
            {
                emit P1_win();
                break;
            }
            stp++;
            world.do_step_2();
            if(world.win()){
                emit P2_win();
                break;
            }
        }
        if(stp<mi)
            mi=stp;
        lminim=stp;
        cminim=mi;
        if(mi<=minim)
        {
            emit finded();
            return;
        }

    }
    for(int i=0; i<all; i++)
    {
        world.clear();
        P1->refresh();
        P2->refresh();
        world.set_O(P1);
        world.set_X(P2);
        int stp=-1;
        while(true)
        {
            stp++;
            world.do_step_1();
            if(world.win())
            {
                emit P2_win();
                break;
            }
            stp++;
            world.do_step_2();
            if(world.win())
            {
                emit P1_win();
                break;
            }
        }
        if(stp<mi)
            mi=stp;
        lminim=stp;
        cminim=mi;
        if(mi<=minim)
        {

            emit finded();
            return;
        }


    }
}
