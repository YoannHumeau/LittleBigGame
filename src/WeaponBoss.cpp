#include "WeaponBoss.h"
#include "BulletBoss.h"

WeaponBoss::WeaponBoss(){}
WeaponBoss::~WeaponBoss(){}

void WeaponBoss::attack(Space& space, Coordinate position) {
    if (lastShoot.getElapsedTime().asSeconds() > 0.1) {
        // set Y position on four differetns places
        position.y = position.y + (100 * ((rand() % 5+1 ) - 3) );
        space.add(std::make_unique<BulletBoss>(position));
        lastShoot.restart();
    }
}