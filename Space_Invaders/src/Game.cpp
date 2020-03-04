#include "Game.h"
#include <memory>
#include "ResourceManager.h"
#include "Ship.h"
#include "font.h"

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
    space.add(std::make_unique<Ship>(*this, space));
}

void Game::endGame()
{
    running = false;
    space.cleanSpace();
}

void Game::display(sf::RenderWindow& window) const
{
    if (!running && space.isEmpty()) {
        window.draw(homeSprite);
    }
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