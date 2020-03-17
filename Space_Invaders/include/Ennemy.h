#ifndef ENNEMY_H
#define ENNEMY_H

#include "Ship.h"

class Ennemy: public Ship
{
    public:
        explicit Ennemy(/*Game& p_game, */Space& p_space, float y);
        virtual void crashReaction(ElementType otherType) override;
        
    private:

        static constexpr float ACCELERATION{300.f};

        virtual void actualiseState() override;
        virtual void update(float time) override;
};

#endif