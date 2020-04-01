#include "Boss.h"
#include "WeaponBoss.h"
#include <math.h>

Boss::Boss(Game &p_game, Space &p_space, float x, float y):
Ennemy(p_game, p_space, x, y, "ressources/ennemy_boss.png")
{
    life = 3;
    eType = EnnemyType::BOSS;
    ACCELERATION = 300.f;
    weapon = std::make_unique<WeaponBoss>();
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

            cpt++;
            float result = amplitude * cos(cpt * M_PI * frequency * time);
            speed += {0, result};
            speed -= speed * COEF_FROTTEMENTS * time;
        }

        if (speed.x == 0)
            weapon->attack(space, position);
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
            game.endGame("ressources/end_win.png");
        }
    }
}