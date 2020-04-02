#ifndef WEAPONBOSS_H
#define WEAPONBOSS_H

#include "Weapon.h"

class WeaponBoss: public Weapon
{
    private:
        int nbWeapons;
    public:
        WeaponBoss(int bossLevel);
        ~WeaponBoss();
        
        virtual void attack(Space& space, Coordinate position) override;

};
#endif