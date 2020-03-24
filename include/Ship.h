#ifndef SHIP_H_INCLUDED
#define SHIP_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Coordinate.h"
#include "Vecteur.h"
#include "PhysicalElement.h"
#include "Explosion.h"
#include "Space.h"
#include "Bullet.h"
#include "Game.h"
#include "Weapon.h"

class Ship : public PhysicalElement
{
    public:
        explicit Ship(Space& p_space, std::string_view path = "ressources/ship.png");

        int life{1};

        virtual void crashReaction(SpaceElement& other) override;

    protected:
        float ACCELERATION;

        std::unique_ptr<Weapon> weapon;
        Space& space;
        sf::Clock lastShoot{};
};

#endif // SHIP_H_INCLUDED
