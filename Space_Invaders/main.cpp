#include <iostream>

#include <SFML/Graphics.hpp>
#include <array>
#include "include/Ship.h"

using namespace std;

constexpr int WINDOW_WITH{1024};
constexpr int WINDOW_HEIGHT{768};

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WITH, WINDOW_HEIGHT), "Space Invaders");
    Coordinate::initialiserEspace(WINDOW_WITH, WINDOW_HEIGHT);
    auto ship = Ship{};
    auto elements = std::array<SpaceElement*, 1>{&ship};
    auto chrono = sf::Clock{};
    while(window.isOpen()) {
        auto event = sf::Event();
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }

        ship.actualiseState();
        auto timeLoop = chrono.restart().asSeconds();
        // ship.update(timeLoop);
        for (auto* element : elements) {
            element->update(timeLoop);
        }

        for (auto* element : elements) {
            if (element != &ship) {
                element->crashTest(ship);
            }
        }

        window.clear();
        // ship.display(window);
        for (auto element : elements) {            element->display(window);
        }
        window.display();
    }
    return 0;
}
