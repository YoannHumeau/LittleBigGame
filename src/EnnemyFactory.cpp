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

std::unique_ptr<SpaceElement> EnnemyFactory::Create(Game &p_game, Space &space, float x, float y, int ennemyType) {

    std::unique_ptr<SpaceElement> ennemies[4] = {
        std::make_unique<Cruiser>(p_game, space, x, y),
        std::make_unique<Reaper>(p_game, space, x, y),
        std::make_unique<Destroyer>(p_game, space, x, y),
        std::make_unique<Boss>(p_game, space, x+200, y),
    };
    if (ennemyType > 0 && ennemyType <= 4)
        return std::move(ennemies[ennemyType-1]);
    return std::move(ennemies[1]);
}