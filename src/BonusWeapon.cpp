#include "BonusWeapon.h"

BonusWeapon::BonusWeapon(Space &p_space, float x, float y):
Bonus(p_space, x, y, "ressources/bonus_weapon.png")
{
    bType = BonusType::BONUS_WEAPON;
    ACCELERATION = 200.f;
}

// void BonusLife::consumeBonus(Player& player) {
//     player.life += 1;
// }