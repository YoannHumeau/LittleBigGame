#ifndef REAPER_H
#define REAPER_H

#include "Ennemy.h"

class Reaper: public Ennemy
{
    private:
        std::string_view paths[3] = {
            "ressources/ennemy_reaper_1.png",
            "ressources/ennemy_reaper_2.png",
            "ressources/ennemy_reaper_3.png"
        };
    public:
        explicit Reaper(Game &p_game, Space& p_space, float x, float y);
        virtual void update(float time) override;
};

#endif