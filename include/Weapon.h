#ifndef WEAPON_H
#define WEAPON_H

#include "Bullet.h"
#include "Space.h"
#include <iostream>

class Weapon
{
    public:
        virtual ~Weapon() {};

        virtual void attack(Space& space, Coordinate position) = 0;

    protected:
        sf::Clock lastShoot{};
};

#endif