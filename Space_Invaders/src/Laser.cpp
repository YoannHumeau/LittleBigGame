#include "Laser.h"

Laser::Laser(){}
Laser::~Laser(){}

void Laser::attack(Space& space, Coordinate position) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && lastShoot.getElapsedTime().asSeconds() > 0.2) {
        std::cout << "Laser" << std::endl;
        // space.add(std::make_unique<Bullet>(position));
        space.add(std::make_unique<Bullet>(position));
        lastShoot.restart();
    }
}