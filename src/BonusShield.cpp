#include "BonusShield.h"

BonusShield::BonusShield(float x, float y):
Bonus(x, y, "ressources/bonus_shield.png")
{
    bType = BonusType::BONUS_SHIELD;
    ACCELERATION = 200.f;
}

void BonusShield::consumeBonus(Player& player) {
    if (player.shield < 3)
        player.shield += 1;
    player.game.setShipState(player.life, player.shield);
}