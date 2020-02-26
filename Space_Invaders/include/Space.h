#ifndef SPACE_H
#define SPACE_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "SpaceElement.h"

class Space
{
    public:
        Space();

        void add(SpaceElement& element);
        void actualized();
        void manageCrash();
        void display(sf::RenderWindow& window) const;
        void cleanSpace();

    protected:

    private:
        std::vector<SpaceElement*> elements{};
        sf::Clock chrono{};
};

#endif // SPACE_H
