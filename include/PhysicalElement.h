#ifndef PHYSICALELEMENT_H
#define PHYSICALELEMENT_H

#include "SpaceElement.h"

class PhysicalElement: public SpaceElement
{
    public:
        explicit PhysicalElement(std::string_view path);
    protected:
        virtual void crashReaction(SpaceElement& other) = 0;
        virtual void update(float time) override;
        virtual void crashTest(SpaceElement& other) override;
        static constexpr float COEF_FROTTEMENTS{2.f};

};

#endif