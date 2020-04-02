#include "Boss.h"
#include "WeaponBoss.h"
#include <math.h>

Boss::Boss(Game &p_game, Space &p_space, float x, float y):
Ennemy(p_game, p_space, x, y, "ressources/ennemy_boss_1.png")
{
    changeSprite("ressources/ennemy_boss_"+std::to_string(game.getLevel())+".png");
    life = 20 * game.getLevel();
    eType = EnnemyType::BOSS;
    ACCELERATION = 300.f;
    weapon = std::make_unique<WeaponBoss>(game.getLevel());
}

void Boss::update(float time) {
    bool bossFullInScreen = isBossFullInScreen();
   
    if (!destruct) {
        if (!bossFullInScreen) {
            speed += {-ACCELERATION * time, 0.f}; 
            if (type != ElementType:: BULLET) {
                speed -= speed * COEF_FROTTEMENTS * time;
            }
        } else if (speed.x == 0) {
            if ( (position.y > 452 && direction == 1) || (position.y < 365 && direction == -1) )
                direction *= -1;
            speed += {0.f, direction * ACCELERATION * time};
            speed -= speed * COEF_FROTTEMENTS * time;
        } else {
            speed.x = 0;
        }

        if (speed.x == 0)
            weapon->attack(space, position);
    }
}

void Boss::crashReaction(SpaceElement& other) {
    if (other.type == ElementType::BULLET || other.type == ElementType::PLAYER) {
        if (life > 0) {
            life -= 1;
        } else {
            space.add(std::make_unique<Explosion>(position));
            destruct = true;
            game.addPoints(sprite.getScale().x * 150);
            if (game.getLevel() < 3) {
                game.nextLevel();
                game.endGame("ressources/end_level.png");
            } else {
                game.restartGameLevel();
                game.endGame("ressources/end_win.png");
            }
        }
    }
}