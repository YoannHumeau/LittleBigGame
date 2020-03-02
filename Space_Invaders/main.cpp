#include <iostream>
#include <memory>

#include <SFML/Graphics.hpp>
#include "include/Ship.h"
#include "include/Space.h"

using namespace std;

constexpr int WINDOW_WITH{1024};
constexpr int WINDOW_HEIGHT{768};
const sf::Color SHIP_COLOR{sf::Color{0, 120, 255}};

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WITH, WINDOW_HEIGHT), "Space Invaders");
    Coordinate::initialiserEspace(WINDOW_WITH, WINDOW_HEIGHT);
    auto space = Space{};
 
    // auto ship = Ship{space};
    // std::unique_ptr<SpaceElement> ship = std::unique_ptr<SpaceElement>{nullptr};
    // auto ship = std::unique_ptr<SpaceElement>{nullptr};

    auto startGame{false};
    while(window.isOpen()) {
        auto event = sf::Event();
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed && !startGame) {
                // ship = std::make_unique<Ship>(space);
                space.add(std::make_unique<Ship>(space));
                startGame = true;
            }
        }

        space.actualized();
        space.manageCrash();
        space.cleanSpace();

        window.clear();
        space.display(window);
        window.display();
    }
    return 0;
}
