#include "Space.h"

Space::Space()
{
    //ctor
}

void Space::add(std::unique_ptr<SpaceElement> element) {
    elements.push_back(std::move(element));
}

void Space::actualized() {
    auto timeLoop = chrono.restart().asSeconds();
    // ship.update(timeLoop);
    for (auto& element : elements) {
        element->actualize(timeLoop);
    }
}

void Space::manageCrash() {
    for (auto i{0u}; i< elements.size(); ++i) {
        for (auto j{0u}; j< elements.size(); ++j) {
            if (i != j) {
                elements[i]->crashTest(*elements[j]);
            }
        }
    }
}

void Space::display(sf::RenderWindow& window) const {
    for (auto& element : elements) {
        element->display(window);
    }
}

void Space::cleanSpace() {
    auto endTable = std::remove_if(std::begin(elements), std::end(elements), SpaceElement::isDestruct);
    elements.erase(endTable, std::end(elements));
}
