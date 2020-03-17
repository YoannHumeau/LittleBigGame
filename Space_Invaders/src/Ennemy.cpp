#include "Ennemy.h"

Ennemy::Ennemy(Space& p_space, float y):
Ship(p_space, "ressources/asteroide.png")
{
    position = Coordinate{750, y};
    type = ElementType::ENNEMY;
}

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
    }
}

void Ennemy::crashReaction(ElementType otherType) {

    if (otherType == ElementType::BULLET) {
        destruct = true;
        space.add(std::make_unique<Explosion>(position));
    }
}