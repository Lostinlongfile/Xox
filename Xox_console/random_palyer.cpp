#include "random_palyer.h"
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;
class point{
public:
    point(int a,int b):x(a),y(b){}
    int x;
    int y;
    void show()
    {
        cout<<" ("<<x<<";"<<y<<") ";
    }
};
random_palyer::random_palyer()
{
    //ctor
}
void random_palyer::refresh()
{
    //ctor
}
void random_palyer::do_move(InfiniteFild *zeon){
    vector<point> avalible;
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
        zeon->set(0,0,type);
        return;
    }

    int n=rand()%avalible.size();
    zeon->set(avalible[n].x,avalible[n].y,type);
}
const char * random_palyer::get_name(){
    return "Random Player v0.1";
}
void random_palyer::set_type(short type){
    this->type=type;
}