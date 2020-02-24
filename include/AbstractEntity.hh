#ifndef ABSTRACTENTITY_HH
#define ABSTRACTENTITY_HH

#include "ISerializable.hh"
#include <iostream>

class AbstractEntity: public ISerializable
{
    public:
        AbstractEntity();
        virtual ~AbstractEntity() {};

        virtual void Draw(void) = 0;
        virtual void Update(void) = 0;
};

#endif