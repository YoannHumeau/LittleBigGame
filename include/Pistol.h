#ifndef PISTOL_H
#define PISTOL_H

#include "Weapon.h"

class Pistol: public Weapon
{

    public:
        Pistol();
        ~Pistol();
        
        virtual void attack(Space& space, Coordinate position) override;

};
#endif