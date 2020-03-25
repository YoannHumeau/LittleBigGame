#include "Space.h"
#include "EnnemyFactory.h"
#include "BonusFactory.h"
#include "TimeManager.h"

Space::Space()
{
    //ctor
}

void Space::add(std::unique_ptr<SpaceElement> element) {
    toAdd.push_back(std::move(element));
}

void Space::addBonuses(int nbBonuses) {
    add(BonusFactory::GetInstance().Create(*this, 1000, 700, nbBonuses));
}

void Space::actualized() {
    TimeManager::GetInstance().Update();
    auto timeLoop = TimeManager::GetInstance().GetElapsedTime();

    for (auto i{0u}; i < elements.size(); ++i) {
        elements[i]->actualize(timeLoop);
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
    for (auto& element : toAdd)
        elements.push_back(std::move(element));
    toAdd.clear();
}

void Space::purge() {
    elements.clear();
    toAdd.clear();
}
