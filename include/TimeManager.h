#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include <SFML/Graphics.hpp>
#include <chrono>
#include <vector>

class TimeManager
{
    private:
        TimeManager();
        ~TimeManager();

        float timing{0.f};
        static TimeManager _instance;
        
        sf::Clock _clock{};

        // avoid copy by rewrited operators
        TimeManager& operator= (const TimeManager&){return this->_instance;}
        TimeManager (const TimeManager&){}

    public:
        static TimeManager &GetInstance(void);
        
        void Update(void);
        float GetElapsedTime(void) const;
};

#endif 