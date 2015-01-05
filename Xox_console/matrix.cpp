#include "matrix.h"

Matrix::Matrix()
{
    zeon=new InfiniteFild();

}
void Matrix::do_step_1()
{
    point t=X->do_move(zeon);
    zeon->set(t.x,t.y,2);
}

void Matrix::do_step_2()
{
    point t=O->do_move(zeon);
    zeon->set(t.x,t.y,1);
}
