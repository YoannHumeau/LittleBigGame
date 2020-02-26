#include "../include/Ship.h"

#include <iostream>

Ship::Ship(Space& p_space) : SpaceElement("ressources/ship.png"), space{p_space} {}

void Ship::actualiseState() {
    beingAcceleratedFront = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    beingAcceleratedFrontS = sf::Keyboard::isKeyPressed(sf::Keyboard::Z);
    beingAcceleratedBack = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
    beingAcceleratedBackS = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
    beingAcceleratedLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    beingAcceleratedLeftS = sf::Keyboard::isKeyPressed(sf::Keyboard::Q);
    beingAcceleratedRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    beingAcceleratedRightS = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
}

void Ship::update(float time) {
    actualiseState();
    if (beingAcceleratedFront || beingAcceleratedFrontS) {
        speed += {0.f, -ACCELERATION * time};
    }
    if (beingAcceleratedBack || beingAcceleratedBackS) {
        speed += {0.f, ACCELERATION * time};
    }
    if (beingAcceleratedLeft || beingAcceleratedLeftS) {
        speed += {-ACCELERATION * time, 0.f};
    }
    if (beingAcceleratedRight || beingAcceleratedRightS) {
        speed += {ACCELERATION * time, 0.f};
    }
    speed -= speed * COEF_FROTTEMENTS * time;
}

void Ship::crashReaction() {
    explosion.start(position);
    space.add(explosion);
}




