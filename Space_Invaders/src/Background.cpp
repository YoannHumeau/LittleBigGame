#include "Background.h"

Background::Background():
SpaceElement("ressources/map3.png")
{
	sprite.setOrigin(0, 0);
	sprite.setPosition(0, 0);
    type = ElementType::OTHER;
    ACCELERATION = 20.f;
}

void Background::crashReaction(ElementType otherType) {
    if (otherType != ElementType::OTHER)
        std::cout << "ok" << std::endl;
}

void Background::update(float time) {
    speed += {-ACCELERATION * time, 0.f};
}