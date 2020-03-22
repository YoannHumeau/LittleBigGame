#include "BonusShield.h"

BonusShield::BonusShield(Space &p_space, float x, float y):
Bonus(p_space, x, y, "ressources/bonus_shield.png")
{
    bType = BonusType::BONUS_SHIELD;
    ACCELERATION = 200.f;
}

// void BonusLife::consumeBonus(Player& player) {
//     player.life += 1;
// }