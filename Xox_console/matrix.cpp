#include "matrix.h"

Matrix::Matrix()
{
    zeon=new InfiniteFild();

}
void Matrix::do_step_1()
{
    X->do_move(zeon);
}

void Matrix::do_step_2()
{
    O->do_move(zeon);
}
