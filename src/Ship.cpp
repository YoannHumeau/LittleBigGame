#include "../include/Ship.h"
#include "Pistol.h"

#include <iostream>

Ship::Ship(Space& p_space, std::string_view path):
PhysicalElement(path),
space{p_space} {
    weapon = std::make_unique<Pistol>();
}

void Ship::crashReaction(SpaceElement& other) {
    if (other.type == ElementType::ENNEMY)
        destruct = true;
}