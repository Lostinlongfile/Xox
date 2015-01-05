#include "matrix.h"

Matrix::Matrix():pX(0,0),pO(0,0)
{
    zeon=new InfiniteFild();

}
void Matrix::do_step_1()
{
    pX=X->do_move(zeon);
    zeon->set(pX.x,pX.y,2);
}

void Matrix::do_step_2()
{
    pO=O->do_move(zeon);
    zeon->set(pO.x,pO.y,1);
}
