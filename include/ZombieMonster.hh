#ifndef ZOMBIEMONSTER_HH
#define ZOMBIEMONSTER_HH

#include "Character.hh"

class ZombieMonster: public Character
{
    public:
        ZombieMonster();
        ~ZombieMonster();

        virtual void Update(void) override;
        virtual std::string Serialize(void) override;
};

#endif