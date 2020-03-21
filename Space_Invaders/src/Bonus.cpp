#include "Bonus.h"

Bonus::Bonus(Space& p_space, float x, float y, std::string_view path):
Ship(p_space, path)
{
    position = Coordinate{x, y};
    type = ElementType::BONUS;
}

Bonus::~Bonus() {}

void Bonus::actualiseState() {
    if (!destruct) {
        beingAcceleratedLeft = true;
        // attack();
    }
}

void Bonus::update(float time) {
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

void Bonus::crashReaction(ElementType otherType) {
    // Detect if Bonus is owned by player
    if (otherType == ElementType::PLAYER) {
        destruct = true;
        space.add(std::make_unique<Explosion>(position));
    }
}