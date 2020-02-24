#include "include/ZombieMonster.hh"
#include "include/TimeManager.hh"
#include "include/json.hpp"

using json = nlohmann::json;

ZombieMonster::ZombieMonster():
Character()
{
    this->SetLife(100);
    this->SetX(0);
    this->SetY(0);
    this->SetClassName("ZombieMonster");
}

ZombieMonster::~ZombieMonster() {}

void ZombieMonster::Update(void)
{
    // 0.001 par 1 ms, soit 1/1s
    TimeManager &tm = TimeManager::GetInstance();
    double ms = tm.GetElapsedTime();
    ms /= 1000;

    this->SetX(this->GetX() + ms);
    this->SetY(this->GetY() + ms);
}

std::string ZombieMonster::Serialize()
{
    json json = 
    {
        { "class", this->GetClassName() },
        { "x", this->GetX() },
        { "y", this->GetY() }, 
        { "life", this->GetLife() }
    };
    // Return the stringified JSON
    return json.dump(4);
}