#ifndef BONUSFACTORY_H
#define BONUSFACTORY_H

class Bonus;
// class SpaceElement;

#include "SpaceElement.h"

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
        std::unique_ptr<SpaceElement> Create(float x, float y, int bonusType);
};

#endif