#ifndef ENNEMYFACTORY_H
#define ENNEMYFACTORY_H

class Ennemy;

// #include "Ennemy.h"
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
        std::unique_ptr<Ennemy> Create(Space &space);
};

#endif