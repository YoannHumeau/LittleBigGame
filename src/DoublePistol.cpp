#include "DoublePistol.h"

DoublePistol::DoublePistol(){}
DoublePistol::~DoublePistol(){}

void DoublePistol::attack(Space& space, Coordinate position) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && lastShoot.getElapsedTime().asSeconds() > 0.1) {
        space.add(std::make_unique<Bullet>(position));
        lastShoot.restart();
    }
}