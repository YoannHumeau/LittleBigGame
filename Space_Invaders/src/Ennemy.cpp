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
        // attack();
    }
}

void Ennemy::update(float time) {
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
        destructOutOfScreen();
    }
}

void Ennemy::crashReaction(ElementType otherType) {

    if (otherType == ElementType::BULLET) {
        destruct = true;
        space.add(std::make_unique<Explosion>(position));
    }
}