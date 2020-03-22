#include "Cruiser.h"

Cruiser::Cruiser(Space &p_space, float x, float y):
Ennemy(p_space, x, y, "ressources/ennemy2.png")
{
    eType = EnnemyType::CRUISER;
    ACCELERATION = 100.f;
}