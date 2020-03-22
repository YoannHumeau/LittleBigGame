#ifndef ENNEMYFACTORY_H
#define ENNEMYFACTORY_H

class Ennemy;

#include "Space.h"

class EnnemyFactory
{
    private:
        EnnemyFactory();
        ~EnnemyFactory();
        static EnnemyFactory _instance;

        // std::unique_ptr<SpaceElement> ennemies[1] {std::unique_ptr<Cruiser>()};
        EnnemyFactory& operator= (const EnnemyFactory&){return this->_instance;}
        EnnemyFactory (const EnnemyFactory&){}

    public:
        static EnnemyFactory& GetInstance(void);
        std::unique_ptr<SpaceElement> Create(Space &space, float x, float y, int ennemyType);
};

#endif