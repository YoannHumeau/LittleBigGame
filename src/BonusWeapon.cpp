#include "BonusWeapon.h"
#include "Laser.h"

BonusWeapon::BonusWeapon(Space &p_space, float x, float y):
Bonus(p_space, x, y, "ressources/bonus_weapon.png")
{
    bType = BonusType::BONUS_WEAPON;
    ACCELERATION = 200.f;
}

void BonusWeapon::consumeBonus(Player& player) {
    // Need the WeaponFactory right here/
    player.weapon = std::make_unique<Laser>();
}