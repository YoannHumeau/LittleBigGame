#ifndef REAPER_H
#define REAPER_H

#include "Ennemy.h"

class Reaper: public Ennemy
{
    public:
        explicit Reaper(Game &p_game, Space& p_space, float x, float y);
};

#endif