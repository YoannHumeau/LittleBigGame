#include "Explosion.h"

Explosion::Explosion() : SpaceElement("ressources/explosion.png")
{
    //ctor
}

void Explosion::start(Coordinate const& p_position) {
    position = p_position;
    starting = true;
}

void Explosion::update(float time) {
    if (starting) {
        age += time;
    }

    if (age < LIFETIME) {
        sprite.setScale(age/LIFETIME, age/LIFETIME);
    }

    SpaceElement::update(time);
}

void Explosion::display(sf::RenderWindow& window) const {
    if (age < LIFETIME) {
        SpaceElement::display(window);
    }
}

void Explosion::crashReaction() {}
