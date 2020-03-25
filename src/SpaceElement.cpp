#include "../include/SpaceElement.h"

#include <iostream>

SpaceElement::SpaceElement(std::string_view const& pathImage) {
    sprite.setTexture(ResourceManager<sf::Texture>::getResource(pathImage));
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    sprite.setPosition(position.getX(), position.getY());
}

void SpaceElement::actualize(float time) {
    update(time);
    auto displacement = speed * time;
    position += displacement;
    sprite.setPosition(position.getX(), position.getY());
}

void SpaceElement::display(sf::RenderWindow& window) const {
    window.draw(sprite);
}

void SpaceElement::screenLimit()
{
    float halfSpriteX = sprite.getLocalBounds().width / 2.f;
    float halfSpriteY = sprite.getLocalBounds().height / 2.f;

    while (position.x > (position.widthSpace - halfSpriteX)) {position.x = (position.widthSpace - halfSpriteX);}
    while (position.x < (0 + halfSpriteX)) {position.x = (0 + halfSpriteX);}
    while (position.y > (position.heightSpace - halfSpriteY)) {position.y = (position.heightSpace - halfSpriteY);}
    while (position.y < (0 + halfSpriteY + marge)) {position.y = (0 + halfSpriteY + marge);}
}

void SpaceElement::destructOutOfScreen()
{
    float halfSpriteX = sprite.getLocalBounds().width / 2.f;

    if (!destruct) {
        if (position.x < (0 - halfSpriteX)) {destruct = true;}
        if (position.x > (position.getWidthSpace() - halfSpriteX) && type == ElementType::BULLET) {destruct = true;}
    }
}

float SpaceElement::getRadius() const {
   return sprite.getLocalBounds().height / 2.f;
}
