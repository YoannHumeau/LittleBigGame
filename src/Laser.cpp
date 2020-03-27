#include "Laser.h"

Laser::Laser(){}
Laser::~Laser(){}

void Laser::attack(Space& space, Coordinate position) {
     if (lastShoot.getElapsedTime().asSeconds() > 0.2) {
        space.add(std::make_unique<Bullet>(position));
        lastShoot.restart();
    }
}