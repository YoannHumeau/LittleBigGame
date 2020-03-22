#include "Pistol.h"

Pistol::Pistol(){}
Pistol::~Pistol(){}

void Pistol::attack(Space& space, Coordinate position) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && lastShoot.getElapsedTime().asSeconds() > 0.2) {
        std::cout << "Pistol" << std::endl;
        space.add(std::make_unique<Bullet>(position));
        lastShoot.restart();
    }
}