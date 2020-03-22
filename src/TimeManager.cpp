#include "TimeManager.h"
#include <chrono>
#include <iostream>

TimeManager TimeManager::_instance = TimeManager();

TimeManager::TimeManager() {}

TimeManager::~TimeManager() {}

TimeManager &TimeManager::GetInstance(void)
{
    return _instance;
}

void TimeManager::Update(void) 
{
    timing = this->_clock.restart().asSeconds();
}

float TimeManager::GetElapsedTime(void) const {
    return timing;
}