#ifndef BULLETBOSS_H
#define BULLETBOSS_H

#include "Coordinate.h"
#include "PhysicalElement.h"
#include "Vecteur.h"
#include <SFML/Audio.hpp>
#include "ResourceManager.h"

class BulletBoss: public PhysicalElement
{
    private:
        static constexpr float VITESSE{-400.f};
    public:
        BulletBoss(Coordinate const& p_position);
        virtual void crashReaction(SpaceElement& other) override;
};

#endif

