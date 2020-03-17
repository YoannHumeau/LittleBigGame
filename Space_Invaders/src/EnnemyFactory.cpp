#include "EnnemyFactory.h"

EnnemyFactory EnnemyFactory::_instance = EnnemyFactory();

EnnemyFactory::EnnemyFactory() {}
EnnemyFactory::~EnnemyFactory() {}

EnnemyFactory &EnnemyFactory::GetInstance() {
    return _instance;
}

std::unique_ptr<Ennemy> EnnemyFactory::Create(Space &space) {

    // space.add(std::make_unique<Ennemy>(space));
    // space.add(std::unique_ptr<Ennemy>());
    return std::make_unique<Ennemy>(space);
    // return std::unique_ptr<Ennemy>();
    // return std::make_unique<Ennemy>(space);
}