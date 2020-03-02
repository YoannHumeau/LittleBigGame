#include "../include/Ship.h"

#include <iostream>

Ship::Ship(Space& p_space) : SpaceElement("ressources/ship.png"), space{p_space} {}

void Ship::actualiseState() {
    beingAcceleratedFront = sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z);
    beingAcceleratedBack = sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S);
    beingAcceleratedLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q);
    beingAcceleratedRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D);
}

void Ship::update(float time) {
    actualiseState();
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
}

void Ship::crashReaction() {
    space.add(std::make_unique<Explosion>(position));
}




