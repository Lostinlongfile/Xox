#ifndef ALEX_PALYER_H
#define ALEX_PALYER_H

#include "base_player.h"
#include <sstream>
#include <iostream>
#include <vector>
struct full_analize
{
    int before;
    bool closed_before;
    int after;
    bool closed_after;
};
class point_info
{
public:
    int wins_me;
    int cat_win;
    int cat_four_unclosed_dual;
    int cat_four_unclosed_partly;
    int cat_thris_unclosed_dual;
    int me_four_unclosed_dual;
    int me_four_unclosed_partly;
    int me_thris_unclosed_dual;
    point_info();
    point_info(InfiniteFild *fild, point p, short type);
    point_info(InfiniteFild *fild,point p,short type,point with);
    void count(point p,int a, int b,short type,InfiniteFild *zeon);
    void count(point p,int a, int b,short type,InfiniteFild *zeon,point with);
    point_info operator+(const point_info& pi);
};

class line
{
public:
    short contain[11];
    point inc[11];
    int fill;
    void push_back(short m,point p){
        contain[fill]=m;
        inc[fill]=p;
        fill++;
    }

    line():fill(0)
    {
        for(int i=0;i<11;i++)
            contain[i]=0;
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
    bool iscontain(point p)
    {
        for(int i=0;i<11;i++)
            if(inc[i]==p)
                return true;
        return false;
    }

};

class alex_palyer : public base_player
{
    public:
        static line get_masive(InfiniteFild *zeon,int x,int y,int dx,int dy);
        point_info get_size_if(InfiniteFild *zeon,short type,point with);
        int type;
        alex_palyer();
        point do_move(InfiniteFild *zeon,std::stringstream &out);
        const char * get_name();
        void set_type(short type);
        void refresh();
};

#endif // ALEX_PALYER_H
