#ifndef WEAPONBOSS_H
#define WEAPONBOSS_H

#include "Weapon.h"

class WeaponBoss: public Weapon
{

    public:
        WeaponBoss();
        ~WeaponBoss();
        
        virtual void attack(Space& space, Coordinate position) override;

};
#endif