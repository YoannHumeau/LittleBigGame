#ifndef SHIP_H_INCLUDED
#define SHIP_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Coordinate.h"
#include "Vecteur.h"
#include "SpaceElement.h"
#include "Explosion.h"
#include "Space.h"

class Ship : public SpaceElement
{
    public:
        explicit Ship(Space& p_space);

        virtual void crashReaction() override;

    protected:
        virtual void update(float time) override;

    private:
        void actualiseState();

        bool beingAcceleratedFront{false};
        bool beingAcceleratedBack{false};
        bool beingAcceleratedLeft{false};
        bool beingAcceleratedRight{false};

        Space& space;
        Explosion explosion{};

        static constexpr float ACCELERATION{700.f};
        static constexpr float COEF_FROTTEMENTS{2.f};
};

#endif // SHIP_H_INCLUDED
