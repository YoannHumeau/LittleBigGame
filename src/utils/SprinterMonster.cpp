#include "include/SprinterMonster.hh"
#include "include/TimeManager.hh"
#include "include/json.hpp"

using json = nlohmann::json;

SprinterMonster::SprinterMonster():
Character()
{
    this->SetLife(25);
    this->SetX(0);
    this->SetY(0);
    this->SetClassName("SprinterMonster");
}

SprinterMonster::~SprinterMonster() {}

void SprinterMonster::Update(void)
{
    // 0.001 par 1 ms, soit 1/1s
    TimeManager &tm = TimeManager::GetInstance();
    double ms = tm.GetElapsedTime();
    ms /= 1000;

    this->SetX(this->GetX()+ (ms * 5));
    this->SetY(this->GetY()+ (ms * 5));
}

std::string SprinterMonster::Serialize()
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