#ifndef DOUBLEPISTOL_H
#define DOUBLEPISTOL_H

#include "Weapon.h"

class DoublePistol: public Weapon
{

    public:
        DoublePistol();
        ~DoublePistol();
        
        virtual void attack(Space& space, Coordinate position) override;

};
#endif