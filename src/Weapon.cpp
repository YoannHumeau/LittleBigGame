#include "Weapon.h"

Weapon::~Weapon(){}

void Weapon::attack(Space& space, Coordinate position) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && lastShoot.getElapsedTime().asSeconds() > 0.2) {
        space.add(std::make_unique<Bullet>(position));
        lastShoot.restart();
    }
}