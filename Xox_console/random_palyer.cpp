#include "random_palyer.h"
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

random_palyer::random_palyer()
{
    //ctor
}
void random_palyer::refresh()
{
    //ctor
}
point random_palyer::do_move(InfiniteFild *zeon){
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
        return point(0,0);
    }

    int n=rand()%avalible.size();
    return avalible[n];
}
const char * random_palyer::get_name(){
    return "Random Player v0.1";
}
void random_palyer::set_type(short type){
    this->type=type;
}
