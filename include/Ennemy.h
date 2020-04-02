#ifndef ENNEMY_H
#define ENNEMY_H

#include "Ship.h"
#include "Game.h"

enum class EnnemyType {CRUISER = 0, REAPER = 1, DESTROYER = 2, BOSS = 3};

class Ennemy: public Ship
{
    public:
        explicit Ennemy(Game &p_game, Space& p_space, float x, float y, std::string_view path);
        ~Ennemy() = 0;
        virtual void crashReaction(SpaceElement& other) override;
        
    protected:
        EnnemyType eType;
        
    private:
        void AskForBonus();
};

#endif