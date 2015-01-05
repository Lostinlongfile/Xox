#include "test_func.h"


int fight(base_player* P1,base_player *P2,int all){

    int d_wins=0;
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
                d_wins++;
                break;
            }
            world.do_step_2();
            if(world.win())
                break;
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
                break;
            }
            world.do_step_2();
            if(world.win())
            {
                d_wins++;
                break;
            }
        }
    }
    return d_wins;
}

void step_by_step_fight(base_player* P1,base_player *P2){
        Matrix world;

        P1->refresh();
        P2->refresh();
        std::cout<<"X --- "<<P1->get_name()<<std::endl;
        std::cout<<"O --- "<<P2->get_name()<<std::endl;
        world.set_X(P1);
        world.set_O(P2);
        while(true)
        {
            world.do_step_1();
            std::cout<<"\n1) "<<world.get_X()->get_name()<<" move:\n";
            world.zeon->show();
            if(world.win())
            {
                std::cout<<"\n"<<world.get_X()->get_name()<<" win!";
                break;
            }
            std::cout<<"\n2) "<<world.get_O()->get_name()<<" move:\n";
            world.do_step_2();
            world.zeon->show();
            if(world.win())
            {
                std::cout<<"\n"<<world.get_O()->get_name()<<" win!";
                break;
            }
            std::cout<<"\nenter any number to go to nest steps\n";
            int t;
            std::cin>>t;
        }
}
