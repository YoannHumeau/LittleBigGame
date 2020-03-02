#include "Explosion.h"

Explosion::Explosion(Coordinate const& p_position) : SpaceElement("ressources/explosion.png")
{
    position = p_position;
}

void Explosion::update(float time) {
    age += time;
    if (age < LIFETIME) {
        sprite.setScale(age/LIFETIME, age/LIFETIME);
    } else {
        destruct = true;
    }
 }

void Explosion::crashReaction() {}
