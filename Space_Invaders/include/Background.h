#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "SpaceElement.h"

class Background: public SpaceElement
{
    public:
        Background();

        virtual void update(float time) override;
        virtual void crashReaction(ElementType otherType) override;

    private:
    	float ACCELERATION;
};

#endif