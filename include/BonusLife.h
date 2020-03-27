#ifndef BONUSLIFE_H
#define BONUSLIFE_H

#include "Bonus.h"

class BonusLife: public Bonus
{
    public:
        explicit BonusLife(Space& p_space, float x, float y);
        void consumeBonus(SpaceElement& player);
        virtual void crashReaction(SpaceElement& player) override;

        //virtual void consumeBonus(Player& player) override;
};

#endif