#include "Reaper.h"

Reaper::Reaper(Game &p_game, Space &p_space, float x, float y):
Ennemy(p_game, p_space, x, y, "ressources/ennemy.png")
{
    eType = EnnemyType::REAPER;
    ACCELERATION = 400.f;
}