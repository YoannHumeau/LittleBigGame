#ifndef TIMEMANAGER_HH
#define TIMEMANAGER_HH

#include <chrono>
#include <vector>

class TimeManager
{
    private:
        static TimeManager _instance;
        std::vector<std::chrono::system_clock::time_point> _chronos;

        TimeManager();
        ~TimeManager();

        // avoid copy by rewrited operators
        TimeManager& operator= (const TimeManager&){return this->_instance;}
        TimeManager (const TimeManager&){}

    public:
        static TimeManager &GetInstance(void);
        
        void Start(void);
        void Update(void);

        unsigned int GetElapsedTime(void) const;
        unsigned int GetStartedTime(void) const;
};

#endif 