#ifndef ALEX_PALYER_H
#define ALEX_PALYER_H

#include "base_player.h"
#include <iostream>
#include <vector>
struct full_analize
{
    int before;
    bool closed_before;
    int after;
    bool closed_after;
};

class line
{
public:
    short contain[11];
    int fill;
    void push_back(short m){
        contain[fill]=m;
        fill++;
    }

    line():fill(0)
    {
        for(int i=0;i<11;i++)
            contain[i]=0;
    }

    line(int a1,int a2,int a3,int a4,int a5,int a6,int a7,int a8,int a9,int a10,int a11):fill(0){
        contain[0]=a1;  //-5
        contain[1]=a2;  //-4
        contain[2]=a3;  //-3
        contain[3]=a4;  //-2
        contain[4]=a5;  //-1
        contain[5]=a6;//0
        contain[6]=a7;  //+1
        contain[7]=a8;  //+2
        contain[8]=a9;  //+3
        contain[9]=a10; //+4
        contain[10]=a11;//+5
    }
    full_analize analize_for(int type)
    {
        full_analize out;
        contain[5]=type;
        int m=0;
        for(m=1;m<=5;m++)
            if(contain[5-m]!=type)
                break;
        out.before=m-1;

        out.closed_before=(contain[5-m]!=0);

        for(m=1;m<=5;m++)
            if(contain[5+m]!=type)
                break;
        out.after=m-1;
        out.closed_after=(contain[5+m]!=0);

        return out;
    }
    void show()
    {

        for(int i=0;i<11;i++)
            std::cout<<contain[i]<<" ";
        std::cout<<std::endl;
    }
};

class alex_palyer : public base_player
{
    public:
        line get_masive(InfiniteFild *zeon,int x,int y,int dx,int dy);
        int get_size_if(InfiniteFild *zeon);
        int type;
        alex_palyer();
        point do_move(InfiniteFild *zeon);
        const char * get_name();
        void set_type(short type);
        void refresh();
};

#endif // ALEX_PALYER_H
