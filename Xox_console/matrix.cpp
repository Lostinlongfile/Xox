#include "matrix.h"

Matrix::Matrix():pX(0,0),pO(0,0)
{
    zeon=new InfiniteFild();
    out=new std::ofstream("play.txt");
}
void Matrix::do_step_1()
{
    pX=X->do_move(zeon);
    zeon->set(pX.x,pX.y,2);
    *out<<"X: "<<pX.x<<" "<<pX.y<<std::endl;
}

void Matrix::do_step_2()
{
    pO=O->do_move(zeon);
    zeon->set(pO.x,pO.y,1);
    *out<<"O: "<<pO.x<<" "<<pO.y<<std::endl;
}
