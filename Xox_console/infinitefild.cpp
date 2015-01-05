#include "infinitefild.h"
#include <iostream>
/**********
!!!! первая координата -- номер строки, тобишь Y !!!!!!
!!!! 1 -- O
!!!! 2 -- X
***********/
using namespace std;
InfiniteFild::InfiniteFild():
    min_x(-1),min_y(-1),max_x(1),max_y(1)
{
    vector<short> temp(3,0);

    fild.push_back(temp);
    fild.push_back(temp);
    fild.push_back(temp);
    //ctor
}
short InfiniteFild::get(int x,int y)
{
    if(isExist(x,y)){
        int rx=x-min_x;
        int ry=y-min_y;
        return fild[ry][rx];
    }
    return 0;
}
void InfiniteFild::set(int x,int y,short type)
{
    while(!isNearExist(x,y)){
        if(x>max_x-1)
            add_right_colmn();
        if(x<min_x+1)
            add_left_colmn();
        if(y>max_y-1)
            add_bottom_row();
        if(y<min_y+1)
            add_top_row();
    }

    int rx=x-min_x;
    int ry=y-min_y;
    fild[ry][rx]=type;
}
bool InfiniteFild::isAll(int x,int y,short type)
{
    for(int i=0;i<5;i++)
        if(get(x-i,y)!=type)
            goto step2;
    return true;
step2:
    for(int i=0;i<5;i++)
        if(get(x+i,y)!=type)
            goto step3;
    return true;
step3:
    for(int i=0;i<5;i++)
        if(get(x-i,y-i)!=type)
            goto step4;
    return true;
step4:
    for(int i=0;i<5;i++)
        if(get(x+i,y+i)!=type)
            goto step5;
    return true;
step5:
    for(int i=0;i<5;i++)
        if(get(x,y-i)!=type)
            goto step6;
    return true;
step6:
    for(int i=0;i<5;i++)
        if(get(x,y+i)!=type)
            goto step7;
    return true;
step7:
    for(int i=0;i<5;i++)
        if(get(x+i,y-i)!=type)
            goto step8;
    return true;
step8:
    for(int i=0;i<5;i++)
        if(get(x-i,y+i)!=type)
            goto step9;
    return true;
step9:
    return false;


}
bool InfiniteFild::isTypeWin(short type)
{
    for(int i=min_y;i<=max_y;i++)
        for(int j=min_x;j<=max_x;j++)
            if(get(i,j)==type)
                if(isAll(i,j,type))
                    return true;
    return false;
}
bool InfiniteFild::isExist(int x,int y)
{
    if(x>max_x)
        return false;
    if(x<min_x)
        return false;
    if(y>max_y)
        return false;
    if(y<min_y)
        return false;
    return true;
}
bool InfiniteFild::isNearExist(int x,int y)
{
    if(x>max_x-1)
        return false;
    if(x<min_x+1)
        return false;
    if(y>max_y-1)
        return false;
    if(y<min_y+1)
        return false;
    return true;
}
void InfiniteFild::add_right_colmn()
{
    max_x++;
    for(int i=0;i<fild.size();i++)
        fild[i].push_back(0);
}
void InfiniteFild::add_bottom_row()
{
    max_y++;
    vector<short> add(max_x-min_x+1,0);
    fild.push_back(add);
}
void InfiniteFild::add_top_row()
{
    min_y--;
    vector<short> add(max_x-min_x+1,0);
    fild.insert(fild.begin(),add);
}
void InfiniteFild::add_left_colmn()
{
    min_x--;
    for(int i=0;i<fild.size();i++)
        fild[i].insert(fild[i].begin(),0);
}
InfiniteFild::~InfiniteFild()
{
    //dtor
}
void InfiniteFild::show()
{
    for(int i=min_y;i<=max_y;i++){
        for(int j=min_x;j<=max_x;j++){
            if(get(j,i)==1)
                cout<<"o";
            else if(get(j,i)==2)
                cout<<"x";
            else
                cout<<".";
        }
        cout<<endl;
    }
    //dtor
}
bool InfiniteFild::isAnyNear(int x,int y)
{
    if(get(x-1,y-1)!=0)
        return true;
    if(get(x-1,y)!=0)
        return true;
    if(get(x-1,y+1)!=0)
        return true;
    if(get(x,y-1)!=0)
        return true;
    if(get(x,y+1)!=0)
        return true;
    if(get(x+1,y-1)!=0)
        return true;
    if(get(x+1,y)!=0)
        return true;
    if(get(x+1,y+1)!=0)
        return true;
    return false;
}
