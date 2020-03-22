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

// void SpaceElement::update(float time) {
//     time = time + 0;
// }

void SpaceElement::display(sf::RenderWindow& window) const {
    window.draw(sprite);
}

void SpaceElement::screenLimit()
{
    auto halfSpriteX = sprite.getLocalBounds().width / 2.f;
    auto halfSpriteY = sprite.getLocalBounds().height / 2.f;

    while (position.x > (position.widthSpace - halfSpriteX)) {position.x = (position.widthSpace - halfSpriteX);}
    while (position.x < (0 + halfSpriteX)) {position.x = (0 + halfSpriteX);}
    while (position.y > (position.heightSpace - halfSpriteY)) {position.y = (position.heightSpace - halfSpriteY);}
    while (position.y < (0 + halfSpriteY + marge)) {position.y = (0 + halfSpriteY + marge);}
}

void SpaceElement::destructOutOfScreen()
{
    auto halfSpriteX = sprite.getLocalBounds().width / 2.f;
    auto halfSpriteY = sprite.getLocalBounds().height / 2.f;

    // std::cout << "destruct :: " << destruct << std::endl;
    if (!destruct) {
        if (position.x > (position.widthSpace + halfSpriteX)) {destruct = true; std::cout << "destruct droite :: " << destruct << std::endl;}
        if (position.x < (0 - halfSpriteX)) {destruct = true; std::cout << "destruct gauche  :: " << destruct << std::endl;}
        if (position.y > (position.heightSpace + halfSpriteY)) {destruct = true; std::cout << "destruct haut :: " << destruct << std::endl;}
        if (position.y < (0 - halfSpriteY)) {destruct = true; std::cout << "destruct bas :: " << destruct << std::endl;}
    }
}

// void SpaceElement::backgroundLimit()
// {
//     auto halfSpriteX = sprite.getLocalBounds().width / 2.f;

//     while (position.x > (position.widthSpace - halfSpriteX)) {
//         position.x = (position.widthSpace - halfSpriteX);
//     }
// }

float SpaceElement::getRadius() const {
   return sprite.getLocalBounds().height / 2.f;
}

// void SpaceElement::crashTest(SpaceElement& other) {
//     auto distance = position.calculateDistance(other.position);
//     if (distance < getRadius() + other.getRadius()) {
//         crashReaction(other.type);
//     }
// }
