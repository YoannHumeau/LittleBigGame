#ifndef BONUSFACTORY_H
#define BONUSFACTORY_H

class Bonus;

#include "Space.h"

class BonusFactory
{
    private:
        BonusFactory();
        ~BonusFactory();
        static BonusFactory _instance;

        BonusFactory& operator= (const BonusFactory&){return this->_instance;}
        BonusFactory (const BonusFactory&){}

    public:
        static BonusFactory& GetInstance(void);
        std::unique_ptr<SpaceElement> Create(Space &space, float x, float y, int bonusType);
};

#endif