#include "EnnemyFactory.h"
#include "Cruiser.h"
#include "Reaper.h"
#include "Destroyer.h"
#include "Boss.h"

EnnemyFactory EnnemyFactory::_instance = EnnemyFactory();

EnnemyFactory::EnnemyFactory() {}
EnnemyFactory::~EnnemyFactory() {}

EnnemyFactory &EnnemyFactory::GetInstance() {
    return _instance;
}

std::unique_ptr<SpaceElement> EnnemyFactory::Create(Space &space, float x, float y, int ennemyType) {

    std::unique_ptr<SpaceElement> ennemy = nullptr;
    switch (ennemyType)
    {
    case 1:
        ennemy = std::make_unique<Cruiser>(space, x, y);
        break;
    case 2:
        ennemy = std::make_unique<Reaper>(space, x, y);
        break;
    case 3:
        ennemy = std::make_unique<Destroyer>(space, x, y);
        break;
    case 4:
        ennemy = std::make_unique<Boss>(space, x, y);
        break;
    default:
        ennemy = std::make_unique<Cruiser>(space, x, y);
        break;
    }

    return ennemy;
}