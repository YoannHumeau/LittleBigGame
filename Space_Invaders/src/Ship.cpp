#include "../include/Ship.h"

#include <iostream>

Ship::Ship() : SpaceElement("ressources/ship.png") {}

void Ship::actualiseState() {
    beingAcceleratedFront = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    beingAcceleratedBack = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
    beingAcceleratedLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    beingAcceleratedRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}

void Ship::update(float time) {
    if (beingAcceleratedFront) {
        speed += {0.f, -ACCELERATION * time};
    }
    if (beingAcceleratedBack) {
        speed += {0.f, ACCELERATION * time};
    }
    if (beingAcceleratedLeft) {
        speed += {-ACCELERATION * time, 0.f};
    }
    if (beingAcceleratedRight) {
        speed += {ACCELERATION * time, 0.f};
    }

    speed -= speed * COEF_FROTTEMENTS * time;
    SpaceElement::update(time);
}

Ship::~Ship() {}
