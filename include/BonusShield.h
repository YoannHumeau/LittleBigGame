#ifndef BONUSSHIELD_H
#define BONUSSHIELD_H

#include "Bonus.h"

class BonusShield: public Bonus
{
    public:
        explicit BonusShield(Space& p_space, float x, float y);
        void consumeBonus(SpaceElement& player);
        virtual void crashReaction(SpaceElement& player) override;
        //virtual void consumeBonus(Player& player) override;
};

#endif