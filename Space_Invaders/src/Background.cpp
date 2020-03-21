#include "Background.h"

Background::Background():
SpaceElement("ressources/map3.png")
{
	sprite.setOrigin(0, -50);
	// sprite.setPosition(0, 0);
    type = ElementType::OTHER;
    ACCELERATION = 2.f;
}

void Background::crashTest(SpaceElement& other) {
    if (other.type == other.type)
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