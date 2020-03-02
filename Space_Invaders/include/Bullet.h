#ifndef BULLET_H
#define BULLET_H

#include "Coordinate.h"
#include "SpaceElement.h"
#include "Vecteur.h"

class Bullet: public SpaceElement
{
    private:
        static constexpr float VITESSE{2000.f};

        Coordinate position;
    public:
        Bullet(Coordinate const& p_position);
        virtual void crashReaction(ElementType otherType) override;
};

#endif

