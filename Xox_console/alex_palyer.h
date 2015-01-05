#ifndef ALEX_PALYER_H
#define ALEX_PALYER_H

#include "base_player.h"


class alex_palyer : public base_player
{
    public:
        int type;
        alex_palyer();
        void do_move(InfiniteFild *zeon);
        const char * get_name();
        void set_type(short type);
};

#endif // ALEX_PALYER_H
