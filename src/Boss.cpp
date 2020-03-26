#include "Boss.h"

Boss::Boss(Game &p_game, Space &p_space, float x, float y):
Ennemy(p_game, p_space, x, y, "ressources/ennemy2.png")
{
    life = 10;
    eType = EnnemyType::BOSS;
    ACCELERATION = 0.f;
}