#ifndef SHIP_H_INCLUDED
#define SHIP_H_INCLUDED

#include "SpaceElement.h"

class Ship : public SpaceElement
{
    public:
        Ship();
        ~Ship();

        void actualiseState();
        void update(float time);

    private:
        bool beingAcceleratedFront{false};
        bool beingAcceleratedBack{false};
        bool beingAcceleratedLeft{false};
        bool beingAcceleratedRight{false};

        static constexpr float ACCELERATION{700.f};
        static constexpr float COEF_FROTTEMENTS{2.f};
};

#endif // SHIP_H_INCLUDED
