#include <SFML/Graphics.hpp>
#include "include/Game.h"
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
    auto game = Game{space};
 
     
    // auto ship = Ship{space};
    // std::unique_ptr<SpaceElement> ship = std::unique_ptr<SpaceElement>{nullptr};
    // auto ship = std::unique_ptr<SpaceElement>{nullptr};

    while(window.isOpen()) {
        try {
            auto event = sf::Event();
            while(window.pollEvent(event)) {
                if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    window.close();
                }

                if (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !game.isRunning()) {
                    game.startGame();
                }
            }

            space.actualized();
            space.manageCrash();

            window.clear();
            space.display(window);
            game.display(window);
            window.display();

            space.cleanSpace();
        } catch (std::exception const& exception) {
            game.initException(exception);
        }
    }
    return 0;
}
