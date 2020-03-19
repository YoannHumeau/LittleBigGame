#ifndef REAPER_H
#define REAPER_H

#include "Ennemy.h"

class Reaper: public Ennemy
{
    public:
        explicit Reaper(Space& p_space, float x, float y);
};

#endif