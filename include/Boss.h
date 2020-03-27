#ifndef BOSS_H
#define BOSS_H

#include "Ennemy.h"

class Boss: public Ennemy
{
    public:
        explicit Boss(Game &p_game, Space& p_space, float x, float y);
};

#endif