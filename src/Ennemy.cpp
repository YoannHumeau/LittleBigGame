#include "Ennemy.h"
#include "Bonus.h"

Ennemy::Ennemy(Space& p_space, float x, float y, std::string_view path):
Ship(p_space, path)
{
    position = Coordinate{x, y};
    type = ElementType::ENNEMY;
}

Ennemy::~Ennemy() {}

// void Ennemy::actualiseState() {
//     if (!destruct) {
//         beingAcceleratedLeft = true;
//     }
// }

// void Ennemy::update(float time) {
//     actualiseState();
//     if (!destruct) {
//         speed += {-ACCELERATION * time, 0.f};
//         speed -= speed * COEF_FROTTEMENTS * time;
//         destructOutOfScreen();
//     }
// }

void Ennemy::crashReaction(SpaceElement& other) {

    if (other.type == ElementType::BULLET || other.type == ElementType::PLAYER) {
        destruct = true;
        space.add(std::make_unique<Explosion>(position));
        AskForBonus();
    }
}

void Ennemy::AskForBonus()
{
    int random = rand() % 70;
    int bonus = 0;

    switch (random) {
        case 1:
            bonus = 1;
            break;
        case 2:
            bonus = 2;
            break;
        case 3:
            bonus = 3;
            break;
    }

    if (bonus != 0) { 
        space.addBonuses(bonus, this->position.x, this->position.y);
        std::cout << "LOG INFO : Bonus generate X:" << this->position.x << " Y:" << this->position.y << std::endl;
    }
}