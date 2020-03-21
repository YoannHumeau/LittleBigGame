#include "PhysicalElement.h"

PhysicalElement::PhysicalElement(std::string_view path):
SpaceElement(path) {}

void PhysicalElement::update(float time) {
    speed += {-ACCELERATION * time, 0.f};    
}

void PhysicalElement::crashTest(SpaceElement& other) {
    auto distance = position.calculateDistance(other.position);
    if (distance < getRadius() + other.getRadius()) {
        crashReaction(other.type);
    }
}