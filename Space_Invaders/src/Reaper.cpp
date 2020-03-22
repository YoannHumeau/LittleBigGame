#include "Reaper.h"

Reaper::Reaper(Space &p_space, float x, float y):
Ennemy(p_space, x, y, "ressources/ennemy.png")
{
    eType = EnnemyType::REAPER;
    ACCELERATION = 400.f;
}