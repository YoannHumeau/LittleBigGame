#include "Explosion.h"
#include "ResourceManager.h"

Explosion::Explosion(Coordinate const& p_position) : SpaceElement("ressources/explosion.png")
{
    type = ElementType::OTHER;
    position = p_position;

    sound.setBuffer(ResourceManager<sf::SoundBuffer>::getResource("ressources/explosion.wav"));
    sound.play();
}

void Explosion::update(float time) {
    age += time;
    if (age < LIFETIME) {
        sprite.setScale(age/LIFETIME, age/LIFETIME);
    } else {
        sprite.setScale(0, 0);
        if (sound.getStatus() == sf::Sound::Stopped)
            destruct = true;
    }
 }

void Explosion::crashTest(SpaceElement& other) {
    if (other.type == other.type)
        return;
}

// void Explosion::crashReaction(ElementType otherType) {
//     if (otherType == type)
//         std::cout << "ok" << std::endl;
// }
