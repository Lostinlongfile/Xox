#ifndef TEST_FUNC_H_INCLUDED
#define TEST_FUNC_H_INCLUDED

#include "infinitefild.h"
#include "matrix.h"
#include "alex_palyer.h"
#include "dima_palyer.h"
#include "random_palyer.h"
#include <iostream>

template <typename T1,typename T2>
int fight(int all){

    int d_wins=0;
    for(int i=0; i<all; i++)
    {
        Matrix world;
        T1 *Alex=new T1();
        T2 *Dima=new T2();
        world.set_X(Dima);
        world.set_O(Alex);
        while(true)
        {
            world.do_step_1();
            //cout<<"\n1) "<<world.get_X()->get_name()<<" move:\n";
            //world.zeon->show();
            if(world.win())
            {
                //cout<<"\n"<<world.get_X()->get_name()<<" win!";
                d_wins++;
                break;
            }
            //cout<<"\n2) "<<world.get_O()->get_name()<<" move:\n";
            world.do_step_2();
            //world.zeon->show();
            if(world.win())
            {
                //cout<<"\n"<<world.get_O()->get_name()<<" win!";
                break;
            }
            //int t;
            //cin>>t;
        }
    }
    for(int i=0; i<all; i++)
    {
        Matrix world;
        T1 *Alex=new T1();
        T2 *Dima=new T2();
        world.set_O(Dima);
        world.set_X(Alex);
        while(true)
        {
            world.do_step_1();
            //cout<<"\n1) "<<world.get_X()->get_name()<<" move:\n";
            //world.zeon->show();
            if(world.win())
            {
                //cout<<"\n"<<world.get_X()->get_name()<<" win!";

                break;
            }
            //cout<<"\n2) "<<world.get_O()->get_name()<<" move:\n";
            world.do_step_2();
            //world.zeon->show();
            if(world.win())
            {
                d_wins++;
                //cout<<"\n"<<world.get_O()->get_name()<<" win!";
                break;
            }
            //int t;
            //cin>>t;
        }
    }
    return d_wins;
}

template <typename T1,typename T2>
void step_by_step_fight(){
        Matrix world;
        T1 *Alex=new T1();
        T2 *Dima=new T2();
        std::cout<<"X --- "<<Alex->get_name()<<std::endl;
        std::cout<<"O --- "<<Dima->get_name()<<std::endl;
        world.set_X(Dima);
        world.set_O(Alex);
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

#endif // TEST_FUNC_H_INCLUDED
