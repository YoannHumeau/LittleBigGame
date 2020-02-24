#ifndef SPRINTERMONSTER_HH
#define SPRINTERMONSTER_HH

#include "Character.hh"

class SprinterMonster: public Character
{
    public:
        SprinterMonster();
        ~SprinterMonster();

        virtual void Update(void) override;
        virtual std::string Serialize(void) override;
};

#endif