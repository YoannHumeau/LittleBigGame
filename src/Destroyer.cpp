#include "Destroyer.h"

Destroyer::Destroyer(Space &p_space, float x, float y):
Ennemy(p_space, x, y, "ressources/asteroide.png")
{
    life = 5;
    eType = EnnemyType::DESTROYER;
    ACCELERATION = 50.f;
}