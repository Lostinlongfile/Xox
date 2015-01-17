#ifndef DIMA_PALYER_H
#define DIMA_PALYER_H

#include "base_player.h"

#include <sstream>
class dima_palyer : public base_player
{
    public:
        int type;
        dima_palyer();
        point do_move(InfiniteFild *zeon,std::stringstream &out);
        const char * get_name();
        void set_type(short type);
        void refresh();
};

#endif // DIMA_PALYER_H
