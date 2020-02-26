#ifndef SPACEELEMENT_H
#define SPACEELEMENT_H

#include <SFML/Graphics.hpp>
#include "Vecteur.h"
#include "Coordinate.h"

class SpaceElement
{
    public:
        explicit SpaceElement(std::string_view const& pathImage);
        SpaceElement(SpaceElement const& other) = delete;
        virtual ~SpaceElement() = default;

        void operator=(SpaceElement const& other) = delete;
        void actualize(float time);
        virtual void display(sf::RenderWindow& window) const;

        static inline bool isDestruct(SpaceElement* element) {return element->destruct;};

        float getRadius() const;
        void crashTest(SpaceElement& other);
        virtual void crashReaction() = 0;

    protected:
        virtual void update(float time);
        bool destruct{false};
        sf::Texture texture{};
        sf::Sprite sprite{};
        Coordinate position{};
        Vecteur speed{0.f, 0.f};
};

#endif // SPACEELEMENT_H
