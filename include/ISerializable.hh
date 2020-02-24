#ifndef ISERIALIZABLE_HH
#define ISERIALIZABLE_HH

#include <string>

class ISerializable
{
    public:
        virtual ~ISerializable() {};
        virtual std::string Serialize(void) = 0;
};

#endif