#include "Player.h"

Player::Player(Game& p_game, Space& p_space):
Ship(p_space, "ressources/ship.png"),
game{p_game}
{
    type = ElementType::PLAYER;
    // life = 2;
}

void Player::actualiseState() {
    if (!destruct) {
        beingAcceleratedFront = sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z);
        beingAcceleratedBack = sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S);
        beingAcceleratedLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q);
        beingAcceleratedRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D);
        attack();
    }
}

void Player::update(float time) {
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

void Player::crashReaction(ElementType otherType) {

    // std::cout << " SHIP LIFE : " << life << std::endl;
    if (otherType == ElementType::ENNEMY) {
        // if (shield > 0)
        //     shield -= 1;
        // else {
            if (life < 0) {
                life -= 1;
                // position.
            }
            else {
                std::cout << " SHIP LIFE : " << life << std::endl;
                this->life = life - 1;
                destruct = true;
                game.endGame();
            // }
            // update();
            space.add(std::make_unique<Explosion>(position));
        }
    // } else if (otherType == ElementType::BONUS) {
    //     std::cout << "Consumed bonus" << std::endl;
    //     // element->consume(this);
    // } else if (otherType == ElementType::WEAPON) {
    //     this->weapon = "weapon on";
    // }
}