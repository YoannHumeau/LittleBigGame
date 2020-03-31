#include "Boss.h"

Boss::Boss(Game &p_game, Space &p_space, float x, float y):
Ennemy(p_game, p_space, x, y, "ressources/ennemy3.png")
{
    life = 10;
    eType = EnnemyType::BOSS;
    ACCELERATION = 300.f;
}

void Boss::update(float time) {
    bool bossFullInScreen = isBossFullInScreen();
    
    if (!destruct) {
        if (!bossFullInScreen)
        {
            speed += {-ACCELERATION * time, 0.f}; 
            if (type != ElementType:: BULLET) {
                speed -= speed * COEF_FROTTEMENTS * time;
            }
        }else{
            speed.x = 0;
            ACCELERATION = 0.f;
        }

        destructOutOfScreen();
    }
}

void Boss::crashReaction(SpaceElement& other) {

    if (other.type == ElementType::BULLET || other.type == ElementType::PLAYER) {
        if (life > 0) {
            life -= 1;
        }else{
            space.add(std::make_unique<Explosion>(position));
            destruct = true;
            game.addPoints(sprite.getScale().x * 100);
        }
    }
}