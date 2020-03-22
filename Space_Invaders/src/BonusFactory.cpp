#include "BonusFactory.h"
#include "BonusLife.h"
// #include "Reaper.h"
// #include "Destroyer.h"
// #include "Boss.h"

BonusFactory BonusFactory::_instance = BonusFactory();

BonusFactory::BonusFactory() {}
BonusFactory::~BonusFactory() {}

BonusFactory &BonusFactory::GetInstance() {
    return _instance;
}

std::unique_ptr<SpaceElement> BonusFactory::Create(Space &space, float x, float y, int bonusType) {

    std::unique_ptr<SpaceElement> bonus = nullptr;
    switch (bonusType)
    {
    case 1:
        bonus = std::make_unique<BonusLife>(space, x, y);
        break;
    }

    return bonus;
}