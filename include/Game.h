#ifndef GAME_H
#define GAME_H

#include "Space.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <exception>
#include "EnnemyGeneration.h"

class Game: public std::exception
{
    private:
        bool running{false};

        int score{};
        int bestScore{};
        sf::Text textScore{};
        sf::Text textBestScore{};
        void refreshScore(void);
        void refreshBestScore(void);

        void loadBestScoreFromFile(void);
        void recordBestScoreInFile(void);

        sf::Clock _clock{};

        Space &space;
        sf::Sprite homeSprite;
        sf::Music music;
        sf::Font font;
        std::unique_ptr<sf::Text> textException;

        unsigned int fps;
        sf::Text textFPS{};

        unsigned int fpsCount;
        sf::Clock fpsInterval{};

        std::map<int, std::list<EnnemyToGenerate>> enm;
        int lastGeneration {0};

        void setupMusic(std::string_view path, int volume, bool loop);

        int shipLife{};
        int shipShield{};
        Resource imgLife{};
        Resource imgShield{};
        sf::Text textLife{};
        sf::Text textShield{};

    public:
        Game(Space&, int);

        inline bool isRunning() const { return running;};

        void addPoints(int);
        void startGame();
        void generateEnnemies();
        void endGame();
        void display(sf::RenderWindow&) const;
        void initException(std::exception const&);

        void updateFps(void);
        unsigned int getFps(void) const;
        void displayFps(int);
        void refreshFps(void);

        void displayShipState(int widthScreen);
        void displayValues(sf::Text &text, sf::Sprite &sprite, int value);
        void refreshLife(int life);
        void refreshShield(int shield);

        void setShipState(int life, int shield);
};

#endif