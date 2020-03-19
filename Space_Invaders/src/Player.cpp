#include "Player.h"

Player::Player(Game& p_game, Space& p_space):
Ship(p_space, "ressources/ship.png"),
game{p_game}
{
    position.x = 1024/6.f;
    position.y = 768/2.f;
    type = ElementType::PLAYER;
    life = 2;
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

// TODO fonciont move à exporter et centraliser, les ennemis bougent aussi !
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
        screenLimit();
    }
}

// TODO : implémenter l'observer pour détruire l'ennemi qui entre en collision avec le player
void Player::crashReaction(ElementType otherType) {

    // if (element.getElementType() == ElementType::ENNEMY) {
    if (otherType == ElementType::ENNEMY) {
        std::cout << " SHIP SHIELD : " << shield << std::endl;
        if (shield > 0) {
            // Destroy the ennemy
            // element.destruct = true;
            shield -= 1;
            space.add(std::make_unique<Explosion>(position));
            position = {100, 100};
        } else {
            std::cout << " SHIP LIFE : " << life << std::endl;
            
            if (life > 1) {
                space.add(std::make_unique<Explosion>(position));
                life -= 1;
                position = {100, 100};
            }
            else {
                this->life = life - 1;
                destruct = true;
                game.endGame();
                space.add(std::make_unique<Explosion>(position));
            }
        }
    // } else if (otherType == ElementType::BONUS) {
    //     std::cout << "Consumed bonus" << std::endl;
    //     // element->consume(this);
    // } else if (otherType == ElementType::WEAPON) {
    //     this->weapon = "weapon on";
    }
}