#ifndef ABSTRACTENTITY_HH
#define ABSTRACTENTITY_HH

#include "ISerializable.hh"
#include <iostream>

class AbstractEntity: public ISerializable
{
    public:
        AbstractEntity();
        virtual ~AbstractEntity() = 0;

        virtual void Draw(void);
        virtual void Update(void);
};

#endif