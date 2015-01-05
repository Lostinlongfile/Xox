#include <iostream>
#include <cstdlib>
#include <time.h>

#include "test_func.h"
using namespace std;

int main()
{
    int tryit=1000;
    srand(time(NULL));
    dima_palyer *Dima=new dima_palyer();
    alex_palyer *Alex=new alex_palyer();
    random_palyer *Random=new random_palyer();

    cout<<"Dima wins (vs Alex) "<<fight(Dima,Alex,tryit)<<" of "<<2*tryit<<endl;
    cout<<"Dima wins (vs Rand) "<<fight(Dima,Random,tryit)<<" of "<<2*tryit<<endl;
    cout<<"Alex wins (vs Rand) "<<fight(Alex,Random,tryit)<<" of "<<2*tryit<<endl;
    cout<<"Dima step by step with Alex\n";
    step_by_step_fight(Dima,Alex);
    return 0;
}
