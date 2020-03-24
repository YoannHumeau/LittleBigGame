#ifndef DESTROYER_H
#define DESTROYER_H

#include "Ennemy.h"

class Destroyer: public Ennemy
{
    public:
        explicit Destroyer(Space& p_space, float x, float y);
};

#endif