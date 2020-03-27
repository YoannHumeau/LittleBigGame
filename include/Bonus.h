#ifndef BONUS_H
#define BONUS_H

#include "Ship.h"
#include "Player.h"

enum class BonusType {BONUS_LIFE = 0, BONUS_SHIELD = 1, BONUS_WEAPON = 2};

class Bonus: public Ship
{
    public:
        explicit Bonus(Space& p_space, float x, float y, std::string_view path);
        ~Bonus() = 0;
        virtual void crashReaction(SpaceElement& other) override;
        void AskForBonus();

    protected:
        BonusType bType;
        virtual void consumeBonus(Player& player) = 0;
};

#endif