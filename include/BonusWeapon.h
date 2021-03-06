#ifndef BONUSWEAPON_H
#define BONUSWEAPON_H

#include "Bonus.h"

class BonusWeapon: public Bonus
{
    public:
        explicit BonusWeapon(float x, float y);
        virtual void consumeBonus(Player& player) override;
};

#endif