#ifndef WEAPON_H
#define WEAPON_H

#include "Bullet.h"
#include "Space.h"
#include <iostream>

class Weapon
{
    public:
        virtual ~Weapon() = 0;

        virtual void attack(Space& space, Coordinate position);

    protected:
        sf::Clock lastShoot{};
};

#endif