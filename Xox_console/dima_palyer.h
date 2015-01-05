#ifndef DIMA_PALYER_H
#define DIMA_PALYER_H

#include "base_player.h"


class dima_palyer : public base_player
{
    public:
        int type;
        dima_palyer();
        void do_move(InfiniteFild *zeon);
        const char * get_name();
        void set_type(short type);
};

#endif // DIMA_PALYER_H
