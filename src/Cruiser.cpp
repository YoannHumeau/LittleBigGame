#include "Cruiser.h"
#include <math.h>

Cruiser::Cruiser(Game &p_game, Space &p_space, float x, float y):
Ennemy(p_game, p_space, x, y, "ressources/ennemy2.png")
{
    eType = EnnemyType::CRUISER;
    ACCELERATION = 500.f;
}

void Cruiser::update(float time) {
    if (!destruct) {
        cpt++;
        float result = amplitude * cos(cpt * M_PI * frequency * time);
        speed += {-ACCELERATION * time, result};
        speed -= speed * COEF_FROTTEMENTS * time;
        destructOutOfScreen();
    }
}