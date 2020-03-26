#ifndef CRUISER_H
#define CRUISER_H

#include "Ennemy.h"
#include <cmath>

class Cruiser: public Ennemy
{
    public:
        explicit Cruiser(Game &p_game, Space& p_space, float x, float y);
        virtual void update(float time) override;
    private:
        float cpt{1};
        float amplitude{20};
        float frequency{0.5};
};

#endif