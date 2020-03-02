#include "../include/Ship.h"

#include <iostream>

Ship::Ship(Space& p_space) : SpaceElement("ressources/ship.png"), space{p_space} {
    type = ElementType::SHIP;
}

void Ship::actualiseState() {
    if (!destroyed) {
        beingAcceleratedFront = sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z);
        beingAcceleratedBack = sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S);
        beingAcceleratedLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q);
        beingAcceleratedRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && lastShoot.getElapsedTime().asSeconds() > 0.1) {
            space.add(std::make_unique<Bullet>(position));
            lastShoot.restart();
        }
    }
}

void Ship::update(float time) {
    actualiseState();
    if (!destroyed) {
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
}

void Ship::crashReaction(ElementType otherType) {

    if (otherType == type)
        std::cout << " ok " << std::endl;

    if (!destroyed) {
        destroyed = true;
        space.add(std::make_unique<Explosion>(position));
    }
}

void Ship::display(sf::RenderWindow& window) const
{
    if (!destroyed)
        SpaceElement::display(window);
    // else
    //     explosion.display(window);
}


