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
        // void crashTest(SpaceElement& other);
        void actualize(float time);
        void operator=(SpaceElement const& other) = delete;

        virtual void display(sf::RenderWindow& window) const;
        // virtual void crashReaction(ElementType otherType) = 0;
        virtual void crashTest(SpaceElement& other) = 0;

        static inline bool isDestruct(std::unique_ptr<SpaceElement>& element) {return element->destruct;};


        Coordinate position{};
        ElementType type{ElementType::OTHER};

    protected:
        bool destruct{false};
        float ACCELERATION{100.f};

        Resource resource{};
        Vecteur speed{0.f, 0.f};

        virtual void update(float time) = 0;
};

#endif // SPACEELEMENT_H
