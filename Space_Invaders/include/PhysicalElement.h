#ifndef PHYSICALELEMENT_H
#define PHYSICALELEMENT_H

#include "SpaceElement.h"

class PhysicalElement: public SpaceElement
{
    public:
        explicit PhysicalElement(std::string_view path);
    protected:
        virtual void crashReaction(ElementType otherType) = 0;
        virtual void update(float time) override;
        virtual void crashTest(SpaceElement& other) override;

};

#endif