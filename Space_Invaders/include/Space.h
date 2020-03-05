#ifndef SPACE_H
#define SPACE_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "SpaceElement.h"

class Space
{
    public:
        Space();

        void add(std::unique_ptr<SpaceElement> element);
        void actualized();
        void manageCrash();
        void display(sf::RenderWindow& window) const;
        void cleanSpace();

        inline bool isEmpty() const {return elements.empty();};

    protected:

    private:
        std::vector<std::unique_ptr<SpaceElement>> elements{};
};

#endif // SPACE_H
