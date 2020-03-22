#include "../include/Ship.h"
#include "Pistol.h"

#include <iostream>

Ship::Ship(/*Game& p_game, */Space& p_space, std::string_view path):
PhysicalElement(path),
// game{p_game},
space{p_space} {
    weapon = std::make_unique<Pistol>();
    // type = ElementType::SHIP;
}

void Ship::actualiseState() {
    if (!destruct) {
        beingAcceleratedFront = sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z);
        beingAcceleratedBack = sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S);
        beingAcceleratedLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q);
        beingAcceleratedRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D);
        // pistol.attack(position);
        // attack();
        // auto test = weapon->attack(position);
        // std::cout << "TEST :: " << test->position.x << " / " << test->position.y << std::endl;
        // space.add(weapon->attack(position));
        // space.add(pistol.attack(position));
    }
}

// void Ship::attack() {
//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && lastShoot.getElapsedTime().asSeconds() > 0.2) {
//         space.add(std::make_unique<Bullet>(position));
//         lastShoot.restart();
//     }
// }

void Ship::update(float time) {
    actualiseState();
    if (!destruct) {
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

void Ship::crashReaction(SpaceElement& other) {

    if (other.type == ElementType::ENNEMY) {
        destruct = true;
        // space.add(std::make_unique<Explosion>(position));
        // game.endGame();
    }
}

// void Ship::display(sf::RenderWindow& window) const
// {
//     if (!destruct)
//         SpaceElement::display(window);
// }


