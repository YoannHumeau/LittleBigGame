#ifndef SHIP_H_INCLUDED
#define SHIP_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Coordinate.h"
#include "Vecteur.h"
#include "PhysicalElement.h"
#include "Explosion.h"
#include "Space.h"
#include "Bullet.h"
#include "Game.h"
#include "Weapon.h"

class Ship : public PhysicalElement
{
    public:
        explicit Ship(Space& p_space, std::string_view path = "ressources/ship.png");

        // virtual void display(sf::RenderWindow& window) const override;
        virtual void crashReaction(SpaceElement& other) override;

        int life{1};

    protected:
        virtual void update(float time) override;
        virtual void actualiseState();
        static constexpr float COEF_FROTTEMENTS{2.f};
        bool beingAcceleratedFront{false};
        bool beingAcceleratedBack{false};
        bool beingAcceleratedLeft{false};
        bool beingAcceleratedRight{false};
        // Game& game;

        Weapon weapon{};
        Space& space;
        sf::Clock lastShoot{};

        float ACCELERATION;
};

#endif // SHIP_H_INCLUDED
