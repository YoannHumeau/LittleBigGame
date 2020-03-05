#ifndef SHIP_H_INCLUDED
#define SHIP_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Coordinate.h"
#include "Vecteur.h"
#include "SpaceElement.h"
#include "Explosion.h"
#include "Space.h"
#include "Bullet.h"
#include "Game.h"

class Ship : public SpaceElement
{
    public:
        explicit Ship(Game& p_game, Space& p_space);

        virtual void display(sf::RenderWindow& window) const override;
        virtual void crashReaction(ElementType otherType) override;

        virtual void attack(void);

    protected:
        virtual void update(float time) override;

    private:
        void actualiseState();

        bool beingAcceleratedFront{false};
        bool beingAcceleratedBack{false};
        bool beingAcceleratedLeft{false};
        bool beingAcceleratedRight{false};

        Game& game;
        Space& space;
        sf::Clock lastShoot{};

        static constexpr float ACCELERATION{700.f};
        static constexpr float COEF_FROTTEMENTS{2.f};
};

#endif // SHIP_H_INCLUDED
