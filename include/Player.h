#ifndef PLAYER_H
#define PLAYER_H

#include "Ship.h"

class Player: public Ship
{
    private:

        // int maxShield{3};
        void actualiseState(void);
        virtual void update(float time) override;

        static constexpr float ACCELERATION{700.f};

        bool beingAcceleratedFront{false};
        bool beingAcceleratedBack{false};
        bool beingAcceleratedLeft{false};
        bool beingAcceleratedRight{false};

    public:
        Game& game;
        int shield{1};
        explicit Player(Game& p_game, Space& p_space);
        virtual void crashReaction(SpaceElement& other) override;
};

#endif