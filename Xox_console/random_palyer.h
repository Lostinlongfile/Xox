#ifndef RANDOM_PALYER_H
#define RANDOM_PALYER_H

#include "base_player.h"


class random_palyer : public base_player
{
    public:
        int type;
        random_palyer();
        void do_move(InfiniteFild *zeon);
        const char * get_name();
        void set_type(short type);
        void refresh();
};

#endif // RANDOM_PALYER_H
