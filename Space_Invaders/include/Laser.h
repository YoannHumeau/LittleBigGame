#ifndef LASER_H
#define LASER_H

#include "Weapon.h"

class Laser: public Weapon
{

    public:
        Laser();
        ~Laser();
        
        virtual void attack(Space& space, Coordinate position) override;

};
#endif