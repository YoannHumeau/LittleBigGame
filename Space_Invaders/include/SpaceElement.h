#ifndef SPACEELEMENT_H
#define SPACEELEMENT_H

#include <SFML/Graphics.hpp>
#include "Vecteur.h"
#include "Coordinate.h"

#include <iostream>

enum class ElementType {SHIP, BULLET, OTHER, ENNEMY};

class SpaceElement
{
    public:
        explicit SpaceElement(std::string_view const& pathImage);
        SpaceElement(SpaceElement const& other) = delete;
        virtual ~SpaceElement() = default;

        void operator=(SpaceElement const& other) = delete;
        void actualize(float time);
        virtual void display(sf::RenderWindow& window) const;

        static inline bool isDestruct(std::unique_ptr<SpaceElement>& element) {return element->destruct;};

        float getRadius() const;
        void crashTest(SpaceElement& other);
        virtual void crashReaction(ElementType otherType) = 0;

    protected:
        bool destruct{false};
        sf::Texture texture{};
        sf::Sprite sprite{};
        Coordinate position{};
        Vecteur speed{0.f, 0.f};
        ElementType type{ElementType::OTHER};

        virtual void update(float time);
};

#endif // SPACEELEMENT_H
