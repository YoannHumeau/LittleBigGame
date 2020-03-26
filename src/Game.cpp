#include "Game.h"
#include <memory>
#include "ResourceManager.h"
#include "Player.h"
#include "font.h"
#include "Ennemy.h"
#include "Bonus.h"
#include "Background.h"
#include "EnnemyGeneration.h"


Game::Game(Space &p_space):
space{p_space}
{
    font.loadFromMemory(Air_Americana_ttf, Air_Americana_ttf_size);
    try {
        homeSprite.setTexture(ResourceManager<sf::Texture>::getResource("ressources/accueil.png"));
        music.openFromFile("ressources/swtheme.wav");
        music.play();
        music.setLoop(true);
    } catch(std::exception const& exception) {
        initException(exception);
    } 
}

void Game::startGame()
{
    running = true;
    
    try {
        music.openFromFile("ressources/imperial_march.wav");
        music.play();
        music.setLoop(true);
    } catch (std::exception const& exception) {
        initException(exception);
    }
    
    _clock.restart();
    space.add(std::make_unique<Background>());
    space.add(std::make_unique<Player>(*this, space));
    
    enm = EnnemyGeneration::GetEnnemiesToGenerate();
}

void Game::generateEnnemies()
{
    if (isRunning()) {
        // for each second, we generate the ennemies
        int now = _clock.getElapsedTime().asSeconds();
        if (lastGeneration != now) {
            std::cout << "LOG INFO : ";
            for (std::list<EnnemyToGenerate>::const_iterator i = enm[now].begin(), end = enm[now].end(); i != end; ++i) {
                std::cout << "Ennemy[" << i->ennemyType << "]atY[" << i->ypos << "]  ";
                space.add(EnnemyFactory::GetInstance().Create(space, 1000, i->ypos, i->ennemyType));
            }
            std::cout << std::endl;
        }
        lastGeneration = now;
    }
}

void Game::generateBonuses()
{
    if (isRunning()) {
        // if (_clock.getElapsedTime().asSeconds() > 2) {
        //     space.addBonuses(2);
        //     _clock.restart().asSeconds();
        // }
    }
}

void Game::endGame()
{
    running = false;
    space.purge();
    music.stop();
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