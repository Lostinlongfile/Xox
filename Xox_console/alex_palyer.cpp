#include "alex_palyer.h"
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;
point_info::point_info():wins_me(0),cat_win(0),
    cat_four_unclosed_dual(0),cat_four_unclosed_partly(0),cat_thris_unclosed_dual(0),
    me_four_unclosed_dual(0),me_four_unclosed_partly(0),me_thris_unclosed_dual(0)
{
}

point_info::point_info(InfiniteFild *fild,point p,short type):wins_me(0),cat_win(0),
    cat_four_unclosed_dual(0),cat_four_unclosed_partly(0),cat_thris_unclosed_dual(0),
    me_four_unclosed_dual(0),me_four_unclosed_partly(0),me_thris_unclosed_dual(0)

{
    count(p,0,-1,type,fild);
    count(p,1,-1,type,fild);
    count(p,1,0,type,fild);
    count(p,1,1,type,fild);
}

std::ostream& operator <<(std::ostream & out,const point_info &pi)
{
#define place(a) #a<<" "<<pi.a<<"\n"
    out<< place(cat_four_unclosed_dual)<<
          place(cat_four_unclosed_partly)<<
          place(cat_thris_unclosed_dual)<<
          place(me_four_unclosed_dual)<<
          place(me_four_unclosed_partly)<<
          place(me_thris_unclosed_dual);
#undef place
}

point_info::point_info(InfiniteFild *fild,point p,short type,point with):wins_me(0),cat_win(0),
    cat_four_unclosed_dual(0),cat_four_unclosed_partly(0),cat_thris_unclosed_dual(0),
    me_four_unclosed_dual(0),me_four_unclosed_partly(0),me_thris_unclosed_dual(0)

{
    count(p,0,-1,type,fild,with);
    count(p,1,-1,type,fild,with);
    count(p,1,0,type,fild,with);
    count(p,1,1,type,fild,with);
}
void point_info::count(point p,int a, int b,short type,InfiniteFild *zeon)
{

    line l=alex_palyer::get_masive(zeon,p.x,p.y,a,b);

    full_analize fa=l.analize_for(3-type);
    full_analize fa_me=l.analize_for(type);
    if(fa_me.after+fa_me.before==4)
        wins_me++;

    if(fa.after+fa.before==4)
        cat_win++;

    if(fa.after+fa.before==3)
    {
        if((!fa.closed_after)&&(!fa.closed_before)){/*незакрытая четыёрка*/
            cat_four_unclosed_dual++;
        }
        else{
        if(!fa.closed_after||!fa.closed_before)/*полузакрытая четвёрка*/
            cat_four_unclosed_partly++;
        }
    }
    if(fa.after+fa.before==2)
    {
        if((!fa.closed_after)&&(!fa.closed_before))
            cat_thris_unclosed_dual++;/*незакрытая тройка*/
    }

    if(fa_me.after+fa_me.before==3)
    {
        if((!fa_me.closed_after)&&(!fa_me.closed_before))/*незакрытая четыёрка*/
            me_four_unclosed_dual++;
        else
        if(!fa_me.closed_after||!fa_me.closed_before)/*полузакрытая четвёрка*/
            me_four_unclosed_partly++;
    }
    if(fa_me.after+fa_me.before==2)
    {
        if((!fa_me.closed_after)&&(!fa_me.closed_before))
            me_thris_unclosed_dual++;/*незакрытая тройка*/
    }

}
void point_info::count(point p,int a, int b,short type,InfiniteFild *zeon,point with)
{

    line l=alex_palyer::get_masive(zeon,p.x,p.y,a,b);
    if(!l.iscontain(with))
        return;
    full_analize fa=l.analize_for(3-type);
    full_analize fa_me=l.analize_for(type);
    /*if(with==point(1,-2))
    {
        cout<<"\ncount (1;-2;~"<<type<<")"<<p<<"+("<<a<<";"<<b<<") : a"<<fa_me.after<<" b"<<fa_me.before<<"\n";
        l.show();
    }*/
    if(fa_me.after+fa_me.before==5)
        wins_me++;


    if(fa.after+fa.before==5)
        cat_win++;

    if(fa.after+fa.before==4)
    {
        if((!fa.closed_after)&&(!fa.closed_before)){/*незакрытая четыёрка*/
            cat_four_unclosed_dual++;
            //cout<<"ud enymy: "<<p<<" "<<a<<" "<<b;
        }
        else{
        if(!fa.closed_after||!fa.closed_before)/*полузакрытая четвёрка*/
            cat_four_unclosed_partly++;}
    }
    if(fa.after+fa.before==3)
    {
        if((!fa.closed_after)&&(!fa.closed_before))
            cat_thris_unclosed_dual++;/*незакрытая тройка*/
    }

    if(fa_me.after+fa_me.before==4)
    {
        if((!fa_me.closed_after)&&(!fa_me.closed_before))/*незакрытая четыёрка*/
        {
            //cout<<"ud me: "<<p<<" "<<a<<" "<<b;
            //l.show();
            me_four_unclosed_dual++;
        }
        else{
        if(!fa_me.closed_after||!fa_me.closed_before)/*полузакрытая четвёрка*/
            me_four_unclosed_partly++;
        }
    }
    if(fa_me.after+fa_me.before==3)
    {
        if((!fa_me.closed_after)&&(!fa_me.closed_before))
            me_thris_unclosed_dual++;/*незакрытая тройка*/
    }

}
point_info point_info::operator+(const point_info& pi)
{
    point_info out;
#define add1(a) out.a = a + pi.a
    //Sout.cat_win=cat_win+pi.cat_win;
    /*out.wins_me =wins_me + pi.wins_me;
                out.cat_win =cat_win + pi.cat_win;
                out.cat_four_unclosed_dual =cat_four_unclosed_dual + pi.cat_four_unclosed_dual;
                out.cat_four_unclosed_partly =cat_four_unclosed_partly + pi.cat_four_unclosed_partly;
                out.cat_thris_unclosed_dual =cat_thris_unclosed_dual + pi.cat_thris_unclosed_dual;
                out.me_four_unclosed_dual =me_four_unclosed_dual + pi.me_four_unclosed_dual;
                out.me_four_unclosed_partly =me_four_unclosed_partly + pi.me_four_unclosed_partly;
                out.me_thris_unclosed_dual =me_thris_unclosed_dual + pi.me_thris_unclosed_dual;*/
            add1(wins_me);
            add1(cat_win);
            add1(cat_four_unclosed_dual);
            add1(cat_four_unclosed_partly);
            add1(cat_thris_unclosed_dual);
            add1(me_four_unclosed_dual);
            add1(me_four_unclosed_partly);
            add1(me_thris_unclosed_dual);


#undef add
    return out;
}

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
    out.fill=0;
    int mix=x-5*dx;//-3-5*(1)=-8
    int miy=y-5*dy;//3-5*(-1)=8
    int max=x+5*dx;//-3+5*(1)=2
    int may=y+5*dy;//3+5*(-1)=-2
    //cout<<"getting "<<mix<<" "<<miy<<" "<<max<<" "<<may<<"\n";
    int i=miy,j=mix;
    while((i!=may)||(j!=max)){
            //cout<<i<<" "<<j<<" "<<zeon->get(j,i)<<endl;
        out.push_back(zeon->get(j,i),point(j,i));
            if(i!=may)
                (may)>(miy)? i++:i--;
            if(j!=max)
                (max)>(mix)? j++:j--;
    }
    out.push_back(zeon->get(j,i),point(j,i));
    return out;
}
point_info alex_palyer::get_size_if(InfiniteFild *zeon,short type,point with)
{
    point_info out;
    for(int i=zeon->get_miy();i<=zeon->get_may();i++){
        for(int j=zeon->get_mix();j<=zeon->get_max();j++){
            if(zeon->get(j,i)==0){
                if(zeon->isAnyNear(j,i)){
                    out=out+point_info(zeon,point(j,i),type,with);
                }
            }
        }
    }

    return out;
}

point alex_palyer::do_move(InfiniteFild *zeon,std::stringstream &out){
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
#define add_to(to) {to.push_back(avalible[i]);continue;}
        point_info pi=point_info(zeon,avalible[i],type);
        if(pi.wins_me!=0)
            return avalible[i];
        if(pi.cat_win!=0)
            add_to(fucking_animals)
        if(pi.cat_four_unclosed_dual)
            add_to(cat_win)
        if((pi.cat_four_unclosed_partly>0)&&(pi.cat_thris_unclosed_dual>0))
            add_to(cat_win)
        if(pi.cat_thris_unclosed_dual>1)
            add_to(cat_win)


        if(pi.me_four_unclosed_dual)
            add_to(me_win)
        if((pi.me_four_unclosed_partly>0)&&(pi.me_thris_unclosed_dual>0))
            add_to(me_win)
        if(pi.me_thris_unclosed_dual>1)
            add_to(me_win)

    }
    out<<"move alize ---------\n";
    out<<"fucking animals\n";
    for(int i=0;i<fucking_animals.size();i++)
        out<<fucking_animals[i];
    out<<endl;
    out<<"Cat wins\n";
    for(int i=0;i<cat_win.size();i++)
        out<<cat_win[i];
    out<<endl;
    out<<"Me wins\n";
    for(int i=0;i<me_win.size();i++)
        out<<me_win[i];
    out<<endl;
    out<<"Me 3 ud\n";
    for(int i=0;i<me_thris_ud.size();i++)
        out<<me_thris_ud[i];
    out<<endl;
    out<<"3 ud\n";
    for(int i=0;i<thris_ud.size();i++)
        out<<thris_ud[i];
    out<<endl;
    if(fucking_animals.size()!=0){
        out<<"пятёрка у врага\n";
        return fucking_animals[0];
    }
    else{
        if(me_win.size()!=0)
        {
            out<<"Моя победная комбинация\n";
            return me_win[0];
        }
        else
        {

            if(cat_win.size()!=0)
            {

                out<<"Врага победная комбинация\n";
                return cat_win[0];
            }
            else
            {
                vector<point> candidats;
                for(int i=0;i<avalible.size();i++)
                {

                    zeon->set(avalible[i].x,avalible[i].y,type);
                   // cout<<" setting "<<avalible[i]<<"\n";// point info"<<pi<<"\n";
                    point_info pi=get_size_if(zeon,type,avalible[i]);
                    zeon->set(avalible[i].x,avalible[i].y,0);
                    if(pi.me_four_unclosed_dual>0)
                    {
                                                out<<"После постановки сюда "<<avalible[i]<<" я получаю  не закрытую четвёрку и этого хватаит\n";
                                                return avalible[i];
                    }
                    if((pi.me_four_unclosed_partly>0)&&(int(pi.me_thris_unclosed_dual/2)>0)){
                        out<<"После постановки сюда "<<avalible[i]<<" я получаю  полузакрытую четвёрку и не закрытую тройку\n";
                        return avalible[i];}
                    if(int(pi.me_thris_unclosed_dual/2)>1){
                        out<<"После постановки сюда "<<avalible[i]<<" я получаю две не закрытые тройки\n";
                        return avalible[i];}
                    if(int(pi.me_thris_unclosed_dual/2)==1){
                        out<<"После постановки сюда "<<avalible[i]<<" я получаю одну не закрытую тройку\n";
                        candidats.push_back(avalible[i]);}
                }

                vector<point> candidats2;
                for(int i=0;i<avalible.size();i++)
                {

                    zeon->set(avalible[i].x,avalible[i].y,3-type);
                    point_info pi=get_size_if(zeon,type,avalible[i]);

                    zeon->set(avalible[i].x,avalible[i].y,0);
                    if(pi.cat_four_unclosed_dual>0)
                    {
                                                out<<"После постановки сюда "<<avalible[i]<<" враг получаю  не закрытую четвёрку и этого хватаит\n";
                                                return avalible[i];
                    }
                    if((pi.cat_four_unclosed_partly>0)&&(int(pi.cat_thris_unclosed_dual/2)>0))
                        return avalible[i];
                    if(int(pi.cat_thris_unclosed_dual/2)>1)
                        return avalible[i];
                    if(int(pi.cat_thris_unclosed_dual/2)==1)
                        candidats2.push_back(avalible[i]);
                }
                if(type==1){
                    if(candidats2.size()!=0)
                    {
                        int n=rand()%candidats2.size();
                        return candidats2[n];
                    }
                    if(candidats.size()!=0)
                    {
                        int n=rand()%candidats.size();
                        return candidats[n];
                    }
                }else
                {

                    if(candidats.size()!=0)
                    {
                        int n=rand()%candidats.size();
                        return candidats[n];
                    }
                    if(candidats2.size()!=0)
                    {
                        int n=rand()%candidats2.size();
                        return candidats2[n];
                    }
                }

            }
        }
    }
    out<<"\nNo_ideas :(\n";
    int n=rand()%avalible.size();
    return avalible[n];
}
const char * alex_palyer::get_name(){
    return "Alex's Player v0.3.2";
}
void alex_palyer::set_type(short type){
    this->type=type;
}
