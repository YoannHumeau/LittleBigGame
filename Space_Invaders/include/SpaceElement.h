#ifndef SPACEELEMENT_H
#define SPACEELEMENT_H

#include <SFML/Graphics.hpp>
#include "Vecteur.h"
#include "Coordinate.h"
#include "ResourceManager.h"
#include "Resource.h"

#include <iostream>

enum class ElementType {PLAYER, BULLET, OTHER, BONUS, WEAPON, ENNEMY};

class SpaceElement: public Resource
{
    public:
        explicit SpaceElement(std::string_view const& pathImage);
        SpaceElement(SpaceElement const& other) = delete;
        virtual ~SpaceElement() = default;

        float getRadius() const;
        void crashTest(SpaceElement& other);
        void actualize(float time);
        void operator=(SpaceElement const& other) = delete;
        inline ElementType getElementType() const {return type;};

        virtual void display(sf::RenderWindow& window) const;
        virtual void crashReaction(ElementType otherType) = 0;

        static inline bool isDestruct(std::unique_ptr<SpaceElement>& element) {return element->destruct;};

    protected:
        bool destruct{false};

        Resource resource{};
        Coordinate position{};
        Vecteur speed{0.f, 0.f};
        ElementType type{ElementType::OTHER};

        virtual void update(float time);
};

#endif // SPACEELEMENT_H
