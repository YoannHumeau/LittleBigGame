#include "BonusLife.h"

BonusLife::BonusLife(Space &p_space, float x, float y):
Bonus(p_space, x, y, "ressources/bonus_life.png")
{
    bType = BonusType::BONUS_LIFE;
    ACCELERATION = 200.f;
}

void BonusLife::consumeBonus(Player& player) {
    // if (player.type == ElementType::PLAYER) {
    //     destruct = true;
    //     Player& p = dynamic_cast<Player&>(player);

        std::cout << "PLAYER LIFE :: " << player.life << std::endl;
        if (player.life < 3)
            player.life += 1;
        std::cout << "PLAYER LIFE AFTER BONUS :: " << player.life << std::endl;
        
        // Bonus::crashReaction(p);
    // }
}