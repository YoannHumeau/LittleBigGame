#include "Reaper.h"

Reaper::Reaper(Game &p_game, Space &p_space, float x, float y):
Ennemy(p_game, p_space, x, y, "ressources/ennemy.png")
{
    eType = EnnemyType::REAPER;
    ACCELERATION = 600.f;
}

void Reaper::update(float time)
{
    if (!destruct) {
        float moveX = -ACCELERATION * time;
        float moveY = -ACCELERATION * time;
        if (game.playerCoord.y > position.y)
            moveY = ACCELERATION * time;
        speed += {moveX, moveY}; 
        speed -= speed * COEF_FROTTEMENTS * time;
        destructOutOfScreen();
    }
}