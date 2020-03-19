#ifndef ENNEMY_H
#define ENNEMY_H

#include "Ship.h"

enum class EnnemyType {CRUISER = 0, REAPER = 1, DESTROYER = 2, BOSS = 3};

class Ennemy: public Ship
{
    public:
        explicit Ennemy(Space& p_space, float x, float y, std::string_view path);
        ~Ennemy() = 0;
        virtual void crashReaction(ElementType otherType) override;
        
    protected:

        EnnemyType eType;

        virtual void actualiseState() override;
        virtual void update(float time) override;
};

#endif