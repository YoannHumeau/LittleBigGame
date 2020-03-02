#include "../include/SpaceElement.h"

#include <iostream>

SpaceElement::SpaceElement(std::string_view const& pathImage) {
    if (!texture.loadFromFile(pathImage.data())) {
        std::cerr << "L'image " << pathImage << " n'a pas été correctement chargée !" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    sprite.setPosition(position.getX(), position.getY());
}

void SpaceElement::actualize(float time) {
    update(time);
    auto displacement = speed * time;
    position += displacement;
    sprite.setPosition(position.getX(), position.getY());
}

void SpaceElement::update(float time) {
    time = time + 0;
}

void SpaceElement::display(sf::RenderWindow& window) const {
    window.draw(sprite);
}

float SpaceElement::getRadius() const {
   return sprite.getLocalBounds().height / 2.f;
}

void SpaceElement::crashTest(SpaceElement& other) {
    auto distance = position.calculateDistance(other.position);
    if (distance < getRadius() + other.getRadius()) {
        crashReaction();
    }
}
