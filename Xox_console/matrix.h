#ifndef MATRIX_H
#define MATRIX_H
#include "infinitefild.h"
#include "base_player.h"
class Matrix
{
    base_player *X,*O;
    public:
        InfiniteFild *zeon;
        Matrix();
        point pX,pO;
        void set_X(base_player * x){X=x;X->set_type(2);};
        void set_O(base_player * o){O=o;O->set_type(1);};
        base_player *get_X(){return X;}
        base_player *get_O(){return O;}
        void do_step_1();
        void do_step_2();
        bool win(){return (zeon->isTypeWin(2)||zeon->isTypeWin(1));}
};

#endif // MATRIX_H
