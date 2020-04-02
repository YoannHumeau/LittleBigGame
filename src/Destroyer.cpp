#include "Destroyer.h"

Destroyer::Destroyer(Game &p_game, Space &p_space, float x, float y):
Ennemy(p_game, p_space, x, y, "ressources/ennemy_destroyer.png")
{
    life = 5;
    eType = EnnemyType::DESTROYER;
    ACCELERATION = 50.f;
}