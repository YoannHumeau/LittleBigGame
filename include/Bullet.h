#ifndef BULLET_H
#define BULLET_H

#include "Coordinate.h"
#include "PhysicalElement.h"
#include "Vecteur.h"
#include <SFML/Audio.hpp>
#include "ResourceManager.h"

class Bullet: public PhysicalElement
{
    private:
        static constexpr float VITESSE{2000.f};
    public:
        Bullet(Coordinate const& p_position);
        virtual void crashReaction(SpaceElement& other) override;
};

#endif

