#include "Bullet.h"


Bullet::Bullet(Coordinate const& p_position) :
PhysicalElement("ressources/bullet.png")
{
    position = p_position;
    speed = Vecteur{VITESSE, 0.1f};
    type = ElementType::BULLET;

    sound.setBuffer(ResourceManager<sf::SoundBuffer>::getResource("ressources/laser.wav"));
    sound.play();
} 

void Bullet::crashReaction(SpaceElement& other)
{
    if (other.type == ElementType::ENNEMY || other.type == ElementType::ENNEMYBULLET)
        destruct = true;
}