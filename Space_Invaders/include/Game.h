#ifndef GAME_H
#define GAME_H

#include "Space.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <exception>
#include "EnnemyFactory.h"
#include "BonusFactory.h"

class Game: public std::exception
{
    private:
        bool running{false};
        int score{};

        sf::Clock _clock{};

        Space &space;
        sf::Sprite homeSprite;
        sf::Font font;
        std::unique_ptr<sf::Text> textException;

    public:
        Game(Space&);

        inline bool isRunning() const { return running;};

        void addPoints(int);
        void startGame();
        void generateEnnemies();
        void generateBonuses();
        void endGame();
        void display(sf::RenderWindow&) const;
        void initException(std::exception const&);
};

#endif