#include "BonusShield.h"

BonusShield::BonusShield(Space &p_space, float x, float y):
Bonus(p_space, x, y, "ressources/bonus_shield.png")
{
    bType = BonusType::BONUS_SHIELD;
    ACCELERATION = 200.f;
}

void BonusShield::crashReaction(SpaceElement& player)
{
    consumeBonus(player);
    Bonus::crashReaction(player);
}

void BonusShield::consumeBonus(SpaceElement& player) {
    if (player.type == ElementType::PLAYER) {
        destruct = true;
        Player& p = dynamic_cast<Player&>(player);

        if (p.shield < 3)
            p.shield += 1;
        // Bonus::crashReaction(p);
    }
}