#include "Ennemy.h"

Ennemy::Ennemy(Space& p_space, float x, float y, std::string_view path):
Ship(p_space, path)
{
    position = Coordinate{x, y};
    type = ElementType::ENNEMY;
}

Ennemy::~Ennemy() {}

void Ennemy::actualiseState() {
    if (!destruct) {
        beingAcceleratedLeft = true;
    }
}

void Ennemy::update(float time) {
    actualiseState();
    if (!destruct) {
        speed += {-ACCELERATION * time, 0.f};
        speed -= speed * COEF_FROTTEMENTS * time;
        destructOutOfScreen();
    }
}

void Ennemy::crashReaction(SpaceElement& other) {

    if (other.type == ElementType::BULLET || other.type == ElementType::PLAYER) {
        destruct = true;
        space.add(std::make_unique<Explosion>(position));
    }
}