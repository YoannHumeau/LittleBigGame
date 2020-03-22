#include "BonusLife.h"

BonusLife::BonusLife(Space &p_space, float x, float y):
Bonus(p_space, x, y, "ressources/ennemy9.png")
{
    bType = BonusType::BONUS_LIFE;
    ACCELERATION = 400.f;
}

// void BonusLife::consumeBonus(Player& player) {
//     player.life += 1;
// }