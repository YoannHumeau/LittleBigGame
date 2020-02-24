#include "MonsterFactory.hh"
#include "ZombieMonster.hh"
#include "SprinterMonster.hh"
#include "json.hpp"
#include <iostream>

using json = nlohmann::json;

MonsterFactory::MonsterFactory() 
{}

MonsterFactory::~MonsterFactory() 
{}

Character *MonsterFactory::Create(const std::string& className)
{
    Character *c = nullptr;
    if (0 == className.compare("ZombieMonster"))
        c = new ZombieMonster();
    else if (0 == className.compare("SprinterMonster"))
        c = new SprinterMonster();
    return c;
}

Character *MonsterFactory::Unserialize(const std::string& jsonString)
{
    // Stringified JSON to Object Json
    json j = json::parse(jsonString);

    Character *c = this->Create(j["class"]);
    c->SetLife(j["life"]);
    c->SetX(j["x"]);
    c->SetY(j["y"]);

    return c;
}