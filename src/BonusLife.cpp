#include "BonusLife.h"

BonusLife::BonusLife(Space &p_space, float x, float y):
Bonus(p_space, x, y, "ressources/bonus_life.png")
{
    bType = BonusType::BONUS_LIFE;
    ACCELERATION = 200.f;
}

void BonusLife::consumeBonus(Player& player) {
    if (player.life < 3)
        player.life += 1;
    player.game.setShipState(player.life, player.shield);
}