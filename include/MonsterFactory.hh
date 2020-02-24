#ifndef MONSTERFACTORY_HH
#define MONSTERFACTORY_HH

#include "Character.hh"

#include <string>

class MonsterFactory 
{
    public:
        MonsterFactory();
        ~MonsterFactory();

        Character *Create(const std::string&);
        Character *Unserialize(const std::string&);
};

#endif