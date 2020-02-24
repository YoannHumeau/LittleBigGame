#include "include/TimeManager.hh"
#include <chrono>

TimeManager TimeManager::_instance = TimeManager();

TimeManager::TimeManager() {}

TimeManager::~TimeManager() {}

TimeManager &TimeManager::GetInstance(void)
{
    return _instance;
}

void TimeManager::Start(void)
{
    // Remise à zéro des compteurs
    this->_chronos.push_back(std::chrono::system_clock::now());
    this->_chronos.push_back(std::chrono::system_clock::now());
    this->_chronos.push_back(std::chrono::system_clock::now());
}

void TimeManager::Update(void) 
{
    this->_chronos.push_back(std::chrono::system_clock::now());
}

// Update2 - Update 1
unsigned int TimeManager::GetElapsedTime(void) const {
    return std::chrono::duration_cast<std::chrono::milliseconds>(
        this->_chronos.at(this->_chronos.size()-1) - this->_chronos.at(this->_chronos.size()-2)
    ).count();
}

// Update - Start
unsigned int TimeManager::GetStartedTime(void) const 
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(
        this->_chronos.at(this->_chronos.size()-1) - this->_chronos.at(0)
    ).count();
}
