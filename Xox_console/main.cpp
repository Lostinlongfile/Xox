#include <iostream>
#include <cstdlib>
#include <time.h>

#include "test_func.h"
using namespace std;

int main()
{
    int tryit=1000;
    srand(time(NULL));
    cout<<"Dima wins (vs Alex) "<<fight<dima_palyer,alex_palyer>(tryit)<<" of "<<2*tryit<<endl;
    cout<<"Dima wins (vs Rand) "<<fight<dima_palyer,random_palyer>(tryit)<<" of "<<2*tryit<<endl;
    cout<<"Alex wins (vs Rand) "<<fight<alex_palyer,random_palyer>(tryit)<<" of "<<2*tryit<<endl;
    cout<<"Dima step by step with Alex\n";
    step_by_step_fight<dima_palyer,alex_palyer>();
    return 0;
}
