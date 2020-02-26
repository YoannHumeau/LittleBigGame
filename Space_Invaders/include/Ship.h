#ifndef SHIP_H_INCLUDED
#define SHIP_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Coordinate.h"
#include "Vecteur.h"
#include "SpaceElement.h"
#include "Explosion.h"

class Ship : public SpaceElement
{
    public:
        explicit Ship();

        void actualiseState();
        virtual void update(float time) override;
        virtual void display(sf::RenderWindow& window) const override;
        virtual void crashReaction() override;

    private:
        bool beingAcceleratedFront{false};
        bool beingAcceleratedBack{false};
        bool beingAcceleratedLeft{false};
        bool beingAcceleratedRight{false};
        bool destruct{false};

        Explosion explosion{};

        static constexpr float ACCELERATION{700.f};
        static constexpr float COEF_FROTTEMENTS{2.f};
};

#endif // SHIP_H_INCLUDED
