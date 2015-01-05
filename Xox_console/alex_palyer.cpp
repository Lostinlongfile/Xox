#include "alex_palyer.h"
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
alex_palyer::alex_palyer()
{
    //ctor
}
void alex_palyer::do_move(InfiniteFild *zeon){
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
const char * alex_palyer::get_name(){
    return "Alex's Player v0.1 (random)";
}
void alex_palyer::set_type(short type){
    this->type=type;
}
