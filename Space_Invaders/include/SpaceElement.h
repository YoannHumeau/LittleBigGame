#ifndef SPACEELEMENT_H
#define SPACEELEMENT_H

#include <SFML/Graphics.hpp>
#include "Vecteur.h"
#include "Coordinate.h"

class SpaceElement
{
    public:
        SpaceElement(std::string_view const& pathImage);

        virtual void update(float time);
        void display(sf::RenderWindow& window) const;
        float getRadius() const;
        void crashTest(SpaceElement& other);

    protected:
        sf::Texture texture{};
        sf::Sprite sprite{};
        Coordinate position{};
        Vecteur speed{0.f, 0.f};
};

#endif // SPACEELEMENT_H
