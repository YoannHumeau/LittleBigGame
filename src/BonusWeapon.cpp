#include "BonusWeapon.h"
#include "Laser.h"

BonusWeapon::BonusWeapon(Space &p_space, float x, float y):
Bonus(p_space, x, y, "ressources/bonus_weapon.png")
{
    bType = BonusType::BONUS_WEAPON;
    ACCELERATION = 200.f;
}

void BonusWeapon::crashReaction(SpaceElement& player)
{
    consumeBonus(player);
    Bonus::crashReaction(player);
}

void BonusWeapon::consumeBonus(SpaceElement& player) {
    if (player.type == ElementType::PLAYER) {
        destruct = true;
        Player& p = dynamic_cast<Player&>(player);

        std::cout << "PLAYER LIFE :: " << p.life << std::endl;
        p.weapon = std::make_unique<Laser>();
        std::cout << "PLAYER LIFE AFTER BONUS :: " << p.life << std::endl;
        
        // Bonus::crashReaction(p);
    }
}