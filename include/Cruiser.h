#ifndef CRUISER_H
#define CRUISER_H

#include "Ennemy.h"
#include <cmath>

class Cruiser: public Ennemy
{
    public:
        explicit Cruiser(Space& p_space, float x, float y);
        virtual void update(float time) override;
    private:
        const double pi = std::acos(-1);
};

#endif