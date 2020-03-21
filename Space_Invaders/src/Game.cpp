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
    if (fpsInterval.getElapsedTime().asSeconds() > 1) {
        fps = fpsCount;
        fpsCount = 0;
        fpsInterval.restart().asSeconds();
        std::cout << "Fps: " << getFps() << '\n';
    }
}


unsigned int Game::getFps() const
{
    return fps;
}

// void Game::processInput()
// {
//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::F12))
//         std::cout << "Fps: " << getFps() << '\n';
// }
