#include "Cruiser.h"
#include <math.h>

Cruiser::Cruiser(Space &p_space, float x, float y):
Ennemy(p_space, x, y, "ressources/ennemy2.png")
{
    eType = EnnemyType::CRUISER;
    ACCELERATION = 100.f;
}

void Cruiser::update(float time) {
//     actualiseState();
    if (!destruct) {
        // std::cout << std::cos(std::acos(-1)/2*time) << std::endl;
        // speed += {std::cos(std::acos(-1)/2*(-ACCELERATION * time)), 0.f};

        // amplitude
        auto A = 2;
        // phase shift
        // auto shift = 1;

        // frequence, nb cycles (inclinaison de la sinusoide)
        // auto f = 0.25;
        for (int i = 0; i < 10; i++){
            auto test = A * -sin(2 * M_PI * i * time)+1;
        
            speed += {-ACCELERATION * time, static_cast<float>(test)};

        }
        // auto accel = static_cast<float>(std::cos(std::acos(-1)/2* (-ACCELERATION * time)));
        // if (position.y > position.getHeightSpace() / 2 && position.y > position.getHeightSpace() - 10)
        // else
            // speed += {-ACCELERATION * time, static_cast<float>(test)};
        // speed += {static_cast<float>(-test), 0.f};
        speed -= speed * COEF_FROTTEMENTS * time;
        destructOutOfScreen();
    }
}