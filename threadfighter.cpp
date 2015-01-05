#include "threadfighter.h"

ThreadFighter::ThreadFighter(QObject *parent) :
    QThread(parent)
{

}
void ThreadFighter::init(base_player *P_1, base_player *P_2, int _all)
{
P1=(P_1),P2=(P_2),all=(_all);
}
void ThreadFighter::run()
{

    for(int i=0; i<all; i++)
    {
        Matrix world;
        P1->refresh();
        P2->refresh();
        world.set_X(P1);
        world.set_O(P2);
        while(true)
        {
            world.do_step_1();
            if(world.win())
            {
                emit P1_win();
                break;
            }
            world.do_step_2();
            if(world.win()){
                emit P2_win();
                break;
            }
        }
    }
    for(int i=0; i<all; i++)
    {
        Matrix world;
        P1->refresh();
        P2->refresh();
        world.set_O(P1);
        world.set_X(P2);
        while(true)
        {
            world.do_step_1();
            if(world.win())
            {
                emit P2_win();
                break;
            }
            world.do_step_2();
            if(world.win())
            {
                emit P1_win();
                break;
            }
        }
    }
}
