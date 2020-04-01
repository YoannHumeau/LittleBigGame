#include "Background.h"

Background::Background(int level):
SpaceElement("ressources/map1.png")
{
    changeSprite("ressources/map"+std::to_string(level)+".png");
    sprite.setOrigin(0, -marge);
    type = ElementType::OTHER;
    ACCELERATION = 2.f;
}

void Background::crashTest(SpaceElement& other) {
    if (other.type == type)
        return;
}

void Background::update(float time) {
    auto halfSpriteX = sprite.getLocalBounds().width / 2.f;

    if (position.x > (position.widthSpace + 250 - (halfSpriteX * 2))) {
        speed += {-ACCELERATION * time, 0.f};
    } else {
        speed -= speed * 2.f * time;
    }
}