#include "BulletBoss.h"


BulletBoss::BulletBoss(Coordinate const& p_position) :
PhysicalElement("ressources/bullet_boss.png")
{
    position = p_position;
    speed = Vecteur{VITESSE, 0};
    type = ElementType::ENNEMYBULLET;
} 

void BulletBoss::crashReaction(SpaceElement& other)
{
    if (other.type == ElementType::PLAYER || other.type == ElementType::BULLET)
        destruct = true;
}