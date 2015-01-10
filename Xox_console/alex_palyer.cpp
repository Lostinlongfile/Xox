#include "alex_palyer.h"
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

alex_palyer::alex_palyer()
{
    //ctor
}
void alex_palyer::refresh()
{
    //ctor
}

line  alex_palyer::get_masive(InfiniteFild *zeon,int x,int y,int dx,int dy)
{
#define who_max(a,b) ((a)>(b)?(a):(b))
#define who_min(a,b) ((a)<(b)?(a):(b))
    line out;
    int mix=x-5*dx;//-1-5*(1)=-6
    int miy=y-5*dy;//1-5*(-1)=4
    int max=x+5*dx;//1+5*1=6
    int may=y+5*dy;//-1+5*(-1)=-6
    //cout<<"getting "<<mix<<" "<<miy<<" "<<max<<" "<<may<<"\n";
    int i=miy,j=mix;
    while((i!=may)||(j!=max)){
            //cout<<i<<" "<<j<<" "<<zeon->get(j,i)<<endl;
            out.push_back(zeon->get(j,i));
            if(i!=may)
                (may)>(miy)? i++:i--;
            if(j!=max)
                (max)>(mix)? j++:j--;
    }
    return out;
}
int alex_palyer::get_size_if(InfiniteFild *zeon)
{
    vector<point> avalible;
    vector<point> cat_win,thris_ud,four_hc,fucking_animals;
    vector<point> me_win,me_thris_ud;

    avalible.clear();
    for(int i=zeon->get_miy();i<=zeon->get_may();i++){
        for(int j=zeon->get_mix();j<=zeon->get_max();j++){
            if(zeon->get(j,i)==0){
                if(zeon->isAnyNear(j,i)){

                    avalible.push_back(point(j,i));
                }
            }
        }
    }
    if(avalible.size()==0){
        return 0;
    }
    //std::cout<<"-------------------------\n";
    for(int i=0;i<avalible.size();i++)
    {
        int four_half_closed=0;
        int thris_unclosed_dual=0;
        int thris_half_closed=0;
        int me_four_half_closed=0;
        int me_thris_unclosed_dual=0;
        int me_thris_half_closed=0;
#define count(a,b) {\
            point a1=avalible[i];\
            line l=this->get_masive(zeon,a1.x,a1.y,(a),(b));\
    /*cout<<a1.x<<" "<<a1.y<<" ("<<(a)<<" "<<(b)<<"):";*/\
    /*l.show();*/\
            full_analize fa=l.analize_for(3-type);\
            full_analize fa_me=l.analize_for(type);\
            if(fa_me.after+fa_me.before==4){/*а я победил!*/\
               return 0;\
            }\
            if(fa.after+fa.before==4){/*всё совсем плохо*/\
                cat_win.push_back(avalible[i]);\
                continue;\
            }\
            if(fa.after+fa.before==3)\
            {\
                if((!fa.closed_after)&&(!fa.closed_before)){/*незакрытая четыёрка*/\
                    cat_win.push_back(avalible[i]);\
                    continue;\
                }\
                if(!fa.closed_after||!fa.closed_before){/*полузакрытая четвёрка*/\
                    four_half_closed++;\
                    four_hc.push_back(avalible[i]);\
                }\
            }\
            if(fa.after+fa.before==2)\
            {\
                if((!fa.closed_after)&&(!fa.closed_before)){\
                    thris_unclosed_dual++;/*незакрытая тройка*/\
                }else{\
                    if(!fa.closed_after)/*полузакрытая тройка*/\
                        thris_half_closed++;\
                    if(!fa.closed_before)/*полузакрытая тройка*/\
                        thris_half_closed++;\
                }\
            }\
       }
        count(0,-1);
        count(1,-1);
        count(1,0);
        count(1,1);
        //ПОсмотрим что может сделать враг
        if(four_half_closed!=0)
        {
            if(four_half_closed>1){
                cat_win.push_back(avalible[i]);
                continue;
            }
            if(thris_unclosed_dual>0){
                cat_win.push_back(avalible[i]);
                continue;
            }
            /*if(thris_half_closed>=1){
                cat_win.push_back(avalible[i]);
                continue;
            }*/

        }
        else{
            if(thris_unclosed_dual>1){
                cat_win.push_back(avalible[i]);
                continue;
            }
        }
    }
    /*cout<<"move alize ---------\n";
    cout<<"Cat wins\n";
    for(int i=0;i<cat_win.size();i++)
        cat_win[i].show();
    cout<<endl;
    cout<<"Me wins\n";
    for(int i=0;i<me_win.size();i++)
        me_win[i].show();
    cout<<endl;
    cout<<"Me thris ud\n";
    for(int i=0;i<me_thris_ud.size();i++)
        me_thris_ud[i].show();
    cout<<endl;
    cout<<"thris ud\n";
    for(int i=0;i<thris_ud.size();i++)
        thris_ud[i].show();
    cout<<endl;*/
    return cat_win.size();
#undef count
}

point alex_palyer::do_move(InfiniteFild *zeon){
    vector<point> avalible;
    vector<point> cat_win,thris_ud,four_hc,fucking_animals;
    vector<point> me_win,me_thris_ud;

    avalible.clear();
    for(int i=zeon->get_miy();i<=zeon->get_may();i++){
        for(int j=zeon->get_mix();j<=zeon->get_max();j++){
            if(zeon->get(j,i)==0){
                if(zeon->isAnyNear(j,i)){

                    avalible.push_back(point(j,i));
                }
            }
        }
    }
    if(avalible.size()==0){
        return point(0,0);
    }
    //std::cout<<"-------------------------\n";
    for(int i=0;i<avalible.size();i++)
    {
        int four_half_closed=0;
        int thris_unclosed_dual=0;
        int thris_half_closed=0;
        int me_four_half_closed=0;
        int me_thris_unclosed_dual=0;
        int me_thris_half_closed=0;
#define count(a,b) {\
            point a1=avalible[i];\
            line l=this->get_masive(zeon,a1.x,a1.y,(a),(b));\
    /*cout<<a1.x<<" "<<a1.y<<" ("<<(a)<<" "<<(b)<<"):";*/\
    /*l.show();*/\
            full_analize fa=l.analize_for(3-type);\
            full_analize fa_me=l.analize_for(type);\
            if(fa_me.after+fa_me.before==4){/*а я победил!*/\
               return avalible[i];\
            }\
            if(fa.after+fa.before==4){/*всё совсем плохо*/\
                fucking_animals.push_back(avalible[i]);\
                continue;\
            }\
            if(fa.after+fa.before==3)\
            {\
                if((!fa.closed_after)&&(!fa.closed_before)){/*незакрытая четыёрка*/\
                    cat_win.push_back(avalible[i]);\
                    continue;\
                }\
                if(!fa.closed_after||!fa.closed_before){/*полузакрытая четвёрка*/\
                    four_half_closed++;\
                    four_hc.push_back(avalible[i]);\
                }\
            }\
            if(fa_me.after+fa_me.before==3)\
            {\
                if((!fa_me.closed_after)&&(!fa_me.closed_before)){/*незакрытая четыёрка*/\
                    me_win.push_back(avalible[i]);\
                    continue;\
                }\
                if(!fa_me.closed_after)/*полузакрытая четвёрка*/\
                    me_four_half_closed++;\
                if(!fa_me.closed_before)/*полузакрытая четвёрка*/\
                    me_four_half_closed++;\
            }\
            if(fa.after+fa.before==2)\
            {\
                if((!fa.closed_after)&&(!fa.closed_before)){\
                    thris_unclosed_dual++;/*незакрытая тройка*/\
                }else{\
                    if(!fa.closed_after)/*полузакрытая тройка*/\
                        thris_half_closed++;\
                    if(!fa.closed_before)/*полузакрытая тройка*/\
                        thris_half_closed++;\
                }\
            }\
            if(fa_me.after+fa_me.before==2)\
            {\
                if((!fa_me.closed_after)&&(!fa_me.closed_before)){\
                    me_thris_unclosed_dual++;/*незакрытая тройка*/\
                }else{\
                    if(!fa_me.closed_after)/*полузакрытая тройка*/\
                        me_thris_half_closed++;\
                    if(!fa_me.closed_before)/*полузакрытая тройка*/\
                        me_thris_half_closed++;\
                }\
            }\
       }
        count(0,-1);
        count(1,-1);
        count(1,0);
        count(1,1);
        //ПОсмотрим что может сделать враг
        if(four_half_closed!=0)
        {
            if(four_half_closed>1){
                cat_win.push_back(avalible[i]);
                continue;
            }
            if(thris_unclosed_dual>0){
                cat_win.push_back(avalible[i]);
                continue;
            }
            /*if(thris_half_closed>=1){
                cat_win.push_back(avalible[i]);
                continue;
            }*/

        }
        else{
            if(thris_unclosed_dual>1){
                cat_win.push_back(avalible[i]);
                continue;
            }
            if(thris_unclosed_dual!=0)
                thris_ud.push_back(avalible[i]);
        }
        //посмотрим что могу сделать я
        if(me_four_half_closed!=0)
        {
            if(me_four_half_closed>1){
                me_win.push_back(avalible[i]);
                continue;
            }
            if(me_thris_unclosed_dual>0){
                me_win.push_back(avalible[i]);
                continue;
            }
            /*if(me_thris_half_closed>=1){
                me_win.push_back(avalible[i]);
                continue;
            }*/

        }
        else{
            if(me_thris_unclosed_dual>1){
                me_win.push_back(avalible[i]);
                continue;
            }
            if(me_thris_unclosed_dual!=0)
                me_thris_ud.push_back(avalible[i]);
        }
    }
    /*cout<<"move alize ---------\n";
    cout<<"fucking animals\n";
    for(int i=0;i<fucking_animals.size();i++)
        fucking_animals[i].show();
    cout<<endl;
    cout<<"Cat wins\n";
    for(int i=0;i<cat_win.size();i++)
        cat_win[i].show();
    cout<<endl;
    cout<<"Me wins\n";
    for(int i=0;i<me_win.size();i++)
        me_win[i].show();
    cout<<endl;
    cout<<"Me thris ud\n";
    for(int i=0;i<me_thris_ud.size();i++)
        me_thris_ud[i].show();
    cout<<endl;
    cout<<"thris ud\n";
    for(int i=0;i<thris_ud.size();i++)
        thris_ud[i].show();
    cout<<endl;*/
    if(fucking_animals.size()!=0){
        return fucking_animals[0];
    }
    else{
        if(cat_win.size()!=0)
        {
            return cat_win[0];
        }
        else
        {
            if(me_win.size()!=0)
            {
                return me_win[0];
            }
            else
            {
                if(four_hc.size()!=0)
                {
                    int n=rand()%four_hc.size();
                    return four_hc[n];
                }
                else{
                    for(int i=0;i<avalible.size();i++)
                    {
                        zeon->set(avalible[i].x,avalible[i].y,3-type);
                        if(get_size_if(zeon)>0){
                            zeon->set(avalible[i].x,avalible[i].y,0);
                            return avalible[i];
                        }
                        zeon->set(avalible[i].x,avalible[i].y,0);

                    }
                    if(me_thris_ud.size()!=0)//
                    {
                        int n=rand()%me_thris_ud.size();
                        return me_thris_ud[n];
                    }
                    else
                    {
                        if(thris_ud.size()!=0)//
                        {
                            int n=rand()%thris_ud.size();
                            return thris_ud[n];
                        }
                    }
                }
            }
        }
    }
#undef count
    int n=rand()%avalible.size();
    return avalible[n];
}
const char * alex_palyer::get_name(){
    return "Alex's Player v0.2.1";
}
void alex_palyer::set_type(short type){
    this->type=type;
}
