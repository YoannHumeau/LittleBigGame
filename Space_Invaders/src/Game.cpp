#include "Game.h"
#include <memory>
#include "ResourceManager.h"
#include "Player.h"
#include "font.h"
#include "Ennemy.h"
#include "Background.h"

Game::Game(Space &p_space):
space{p_space}
{
    font.loadFromMemory(Air_Americana_ttf, Air_Americana_ttf_size);
    try {
        homeSprite.setTexture(ResourceManager<sf::Texture>::getResource("ressources/accueil.png"));
    } catch(std::exception const& exception) {
        initException(exception);
    }
}

void Game::startGame()
{
    running = true;
    space.add(std::make_unique<Background>());
    space.add(std::make_unique<Player>(*this, space));
    space.add(EnnemyFactory::GetInstance().Create(space, 1000, 150, 2));
}

void Game::generateEnnemies()
{
    if (isRunning()) {
        if (_clock.getElapsedTime().asSeconds() > 2) {
            space.addEnnemies(2);
            _clock.restart().asSeconds();
        }
    }
}

void Game::endGame()
{
    running = false;
    space.purge();
}

void Game::display(sf::RenderWindow& window) const
{
    if (!running && space.isEmpty())
        window.draw(homeSprite);

    if (textException)
        window.draw(*textException);

    if (textFPS)
        window.draw(*textFPS);
}

void Game::initException(std::exception const& exception)
{
    textException = std::make_unique<sf::Text>();
    textException->setFont(font);
    textException->setString(exception.what());
    textException->setFillColor(sf::Color::Red);
}

void Game::updateFps()
{
    fpsCount++;
    if (fpsInterval.getElapsedTime().asMilliseconds() > 1000) {
        fps = fpsCount;
        fpsCount = 0;
        fpsInterval.restart().asMilliseconds();
        std::cout << "Fps: " << getFps() << '\n'; 
    }
}


unsigned int Game::getFps() const
{
    return fps;
}


void Game::displayFps(void)
{
    std::string title = "Fps: ";
    unsigned int numberFps = getFps();
    std::string result;
    result = title + std::to_string(numberFps);

    textFPS = std::make_unique<sf::Text>();
    textFPS->setFont(font);
    textFPS->setString(result);
    textFPS->setCharacterSize(18);
    textFPS->setFillColor(sf::Color::White);
    textFPS->setStyle(sf::Text::Bold | sf::Text::Underlined);
    textFPS->setOrigin(0, 0);
}