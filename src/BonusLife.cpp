#include "BonusLife.h"

BonusLife::BonusLife(Space &p_space, float x, float y):
Bonus(p_space, x, y, "ressources/bonus_life.png")
{
    bType = BonusType::BONUS_LIFE;
    ACCELERATION = 200.f;
}

void BonusLife::crashReaction(SpaceElement& player)
{
    consumeBonus(player);
    Bonus::crashReaction(player);
}

void BonusLife::consumeBonus(SpaceElement& player) {
    if (player.type == ElementType::PLAYER) {
        destruct = true;
        Player& p = dynamic_cast<Player&>(player);

        std::cout << "PLAYER LIFE :: " << p.life << std::endl;
        if (p.life < 3)
            p.life += 1;
        std::cout << "PLAYER LIFE AFTER BONUS :: " << p.life << std::endl;
        
        // Bonus::crashReaction(p);
    }
}