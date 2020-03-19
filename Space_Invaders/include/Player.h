#ifndef PLAYER_H
#define PLAYER_H

#include "Ship.h"

class Player: public Ship
{
    private:
        // int maxLife{3};
        int shield{1};
        // int maxShield{3};
        virtual void actualiseState() override;
        virtual void update(float time) override;

        static constexpr float ACCELERATION{700.f};

        Game& game;
        std::string weapon;
        // Weapon& weapon;

    public:
        explicit Player(Game& p_game, Space& p_space);
        virtual void crashReaction(ElementType otherType) override;
};

#endif