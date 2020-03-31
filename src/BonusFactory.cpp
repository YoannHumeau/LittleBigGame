#include "BonusFactory.h"
#include "BonusLife.h"
#include "BonusShield.h"
#include "BonusWeapon.h"

BonusFactory BonusFactory::_instance = BonusFactory();

BonusFactory::BonusFactory() {}
BonusFactory::~BonusFactory() {}

BonusFactory &BonusFactory::GetInstance() {
    return _instance;
}

std::unique_ptr<SpaceElement> BonusFactory::Create(Space &space, float x, float y, int bonusType) {

    std::unique_ptr<SpaceElement> bonus[3] = {
        std::make_unique<BonusLife>(space, x, y),
        std::make_unique<BonusShield>(space, x, y),
        std::make_unique<BonusWeapon>(space, x, y)
    };
    if (bonusType > 0 && bonusType <=3)
        return std::move(bonus[bonusType-1]);
    return std::move(bonus[0]);
}