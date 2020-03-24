#include "Laser.h"

Laser::Laser(){}
Laser::~Laser(){}

void Laser::attack(Space& space, Coordinate position) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        space.add(std::make_unique<Bullet>(position));
        lastShoot.restart();
    }
}