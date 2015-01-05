#ifndef BASE_PLAYER_H
#define BASE_PLAYER_H

#include "infinitefild.h"

class base_player
{
    public:
        base_player();
        virtual void do_move(InfiniteFild *zeon)=0;
        virtual const char * get_name()=0;
        virtual void set_type(short type)=0;
        virtual void refresh()=0;
};

#endif // BASE_PLAYER_H
