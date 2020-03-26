#include "Pistol.h"

Pistol::Pistol(){}
Pistol::~Pistol(){}

void Pistol::attack(Space& space, Coordinate position) {
    if (lastShoot.getElapsedTime().asSeconds() > 0.7) {
        space.add(std::make_unique<Bullet>(position));
        lastShoot.restart();
    }
}