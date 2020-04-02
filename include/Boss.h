#ifndef BOSS_H
#define BOSS_H

#include "Ennemy.h"

class Boss: public Ennemy
{
    public:
        explicit Boss(Game &p_game, Space& p_space, float x, float y);
        virtual void update(float time) override;
        virtual void crashReaction(SpaceElement& other) override;
    private:
        float cpt{1};
        float amplitude{4};
        float frequency{0.5};
};

#endif