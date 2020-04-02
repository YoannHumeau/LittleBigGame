#ifndef BONUSLIFE_H
#define BONUSLIFE_H

#include "Bonus.h"

class BonusLife: public Bonus
{
    public:
        explicit BonusLife(float x, float y);
        virtual void consumeBonus(Player& player) override;
};

#endif