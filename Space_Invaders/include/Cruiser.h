#ifndef CRUISER_H
#define CRUISER_H

#include "Ennemy.h"

class Cruiser: public Ennemy
{
    public:
        explicit Cruiser(Space& p_space, float x, float y);
};

#endif