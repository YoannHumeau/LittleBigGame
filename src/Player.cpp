#include "Player.h"
#include <stdio.h>
#include "Bonus.h"
#include "DoublePistol.h"
#include "Laser.h"

Player::Player(Game& p_game, Space& p_space):
Ship(p_space, "ressources/ship.png"),
game{p_game}
{
    position.x = 1024/6.f;
    position.y = 768/2.f;
    type = ElementType::PLAYER;
    shield = 0;
    life = 1;
    game.setShipState(life, shield);
}

void Player::actualiseState() {
    if (!destruct) {
        // Move spaceship
        beingAcceleratedFront = sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -20);
        beingAcceleratedBack = sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 20);
        beingAcceleratedLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -20);
        beingAcceleratedRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 20);

        // Spaceship attack
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Joystick::isButtonPressed(0, 1))
            weapon->attack(space, position);
    }
}

void Player::update(float time) {
    actualiseState();
    if (!destruct) {
        if (beingAcceleratedFront)
            speed += {0.f, -ACCELERATION * time};
        if (beingAcceleratedBack)
            speed += {0.f, ACCELERATION * time};
        if (beingAcceleratedLeft)
            speed += {-ACCELERATION * time, 0.f};
        if (beingAcceleratedRight)
            speed += {ACCELERATION * time, 0.f};
        speed -= speed * COEF_FROTTEMENTS * time;
        screenLimit();
    }
}

void Player::crashReaction(SpaceElement& other) {
    if (other.type == ElementType::ENNEMY) {
        other.crashTest(*this);
        if (shield > 0) {
            shield -= 1;
        } else {
            if (life > 1)
                position = {100, 100};
            else {
                destruct = true;
                game.endGame();
            }
            life -= 1;
            space.add(std::make_unique<Explosion>(position));
        }
        game.setShipState(life, shield);
    }
}