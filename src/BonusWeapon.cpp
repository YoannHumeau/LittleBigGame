#include "BonusWeapon.h"
#include "Pistol.h"
#include "DoublePistol.h"
#include "Laser.h"

BonusWeapon::BonusWeapon(float x, float y):
Bonus(x, y, "ressources/bonus_weapon.png")
{
    bType = BonusType::BONUS_WEAPON;
    ACCELERATION = 200.f;
}

void BonusWeapon::consumeBonus(Player& player) {
    // Need the WeaponFactory right here/
    std::unique_ptr<Weapon> test[3] = {
        std::make_unique<Pistol>(),
        std::make_unique<DoublePistol>(),
        std::make_unique<Laser>()
    };
    
    int x = rand() % 3;
    player.weapon = std::move(test[x]);
}