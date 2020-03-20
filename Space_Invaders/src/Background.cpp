#include "Background.h"

Background::Background():
SpaceElement("ressources/map2.png")
{
    type = ElementType::OTHER;
    ACCELERATION = 50.f;
}

void Background::crashReaction(ElementType otherType) {
    if (otherType != ElementType::OTHER)
        std::cout << "ok" << std::endl;
}