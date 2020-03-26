#ifndef ENNEMYFACTORY_H
#define ENNEMYFACTORY_H

class Ennemy;

#include "Game.h"
#include "Space.h"

class EnnemyFactory
{
    private:
        EnnemyFactory();
        ~EnnemyFactory();
        static EnnemyFactory _instance;

        EnnemyFactory& operator= (const EnnemyFactory&){return this->_instance;}
        EnnemyFactory (const EnnemyFactory&){}

    public:
        static EnnemyFactory& GetInstance(void);
        std::unique_ptr<SpaceElement> Create(Game &p_game, Space &space, float x, float y, int ennemyType);
};

#endif