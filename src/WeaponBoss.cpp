#include "WeaponBoss.h"
#include "BulletBoss.h"

WeaponBoss::WeaponBoss(int bossLevel){
    nbWeapons = bossLevel;
}
WeaponBoss::~WeaponBoss(){}

void WeaponBoss::attack(Space& space, Coordinate position) {
    if (lastShoot.getElapsedTime().asSeconds() > (0.3 / nbWeapons)) {
        // set Y position on four differetns places

        switch (nbWeapons) {
            case 2:
                position.y += ( (rand() % 2) > 0 ) ? -100 : 100;
                //position.y = position.y + (100 * ((rand() % 2+1 ) - 1) );
                break;
            case 3:
                position.y = position.y + (100 * ((rand() % 5+1 ) - 3) );  
                break;
        }

        //position.y = position.y + (100 * ((rand() % 5+1 ) - 3) );
        space.add(std::make_unique<BulletBoss>(position));
        lastShoot.restart();
    }
}