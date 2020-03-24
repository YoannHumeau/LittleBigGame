#include "PhysicalElement.h"

PhysicalElement::PhysicalElement(std::string_view path):
SpaceElement(path) {}

void PhysicalElement::update(float time) {
    if (!destruct) {
        speed += {-ACCELERATION * time, 0.f}; 
        if (type != ElementType:: BULLET) {
            speed -= speed * COEF_FROTTEMENTS * time;
            destructOutOfScreen();
        }
    }
}

void PhysicalElement::crashTest(SpaceElement& other) {
    auto distance = position.calculateDistance(other.position);
    if (distance < getRadius() + other.getRadius()) {
        crashReaction(other);
    }
}