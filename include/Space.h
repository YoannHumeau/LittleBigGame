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
        void addBonuses(int nbBonuses, float xpos, float ypos);

        void actualized();
        void manageCrash();
        void display(sf::RenderWindow& window) const;
        void cleanSpace();
        void purge();

        inline bool isEmpty() const {return elements.empty();};
        inline bool toClear() const {return toClean;};

    protected:

    private:
        std::vector<std::unique_ptr<SpaceElement>> elements{};
        std::vector<std::unique_ptr<SpaceElement>> toAdd{};
        bool toClean{false};
};

#endif // SPACE_H
