#include "Game.h"
#include <memory>
#include "ResourceManager.h"
#include "Player.h"
#include "font.h"
#include "Ennemy.h"
#include "Bonus.h"
#include "Background.h"
#include "EnnemyGeneration.h"
#include <string>
#include <fstream>

using namespace std::string_literals;

Game::Game(Space &p_space, int widthScreen):
// Game::Game(Space &p_space):
space{p_space}
{
    if (!font.loadFromMemory(Air_Americana_ttf, Air_Americana_ttf_size))
        throw std::runtime_error("Police introuvable");

    textScore.setFont(font);
    textBestScore.setFont(font);
    textBestScore.move(150,0);

    textFPS.setFont(font);
    displayFps(widthScreen);

    loadBestScoreFromFile();

    refreshBestScore();

    try {
        homeSprite.setTexture(ResourceManager<sf::Texture>::getResource("ressources/accueil.png"));
        // music.openFromFile("ressources/swtheme.wav");
        // music.play();
        // music.setVolume(30);
        // music.setLoop(true);
    } catch(std::exception const& exception) {
        initException(exception);
    } 
}

void Game::startGame()
{
    running = true;
    
    try {
        // music.openFromFile("ressources/imperial_march.wav");
        // music.play();
        // music.setVolume(30);
        // music.setLoop(true);
    } catch (std::exception const& exception) {
        initException(exception);
    }
    
    _clock.restart();
    score = 0;
    refreshScore();
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
                space.add(EnnemyFactory::GetInstance().Create(*this, space, 1000, i->ypos, i->ennemyType));
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
    // music.stop();

    recordBestScoreInFile();
}

void Game::display(sf::RenderWindow& window) const
{
    if (textException)
        window.draw(*textException);
    else {
        if (!running && space.isEmpty())
            window.draw(homeSprite);
        else 
            window.draw(textScore);
        window.draw(textFPS);
        window.draw(textBestScore);
    }
}

void Game::initException(std::exception const& exception)
{
    textException = std::make_unique<sf::Text>();
    textException->setFont(font);
    textException->setString(exception.what());
    textException->setFillColor(sf::Color::Red);
}

void Game::setupMusic(std::string_view path, int volume, bool loop)
{
    music.openFromFile(path.data());
    music.play();
    music.setVolume(volume);
    music.setLoop(loop);
}

// FPS Management
void Game::updateFps()
{
    fpsCount++;
    if (fpsInterval.getElapsedTime().asMilliseconds() > 1000) {
        fps = fpsCount;
        fpsCount = 0;
        fpsInterval.restart().asMilliseconds();
    }
}

void Game::displayFps(int widthScreen)
{
    textFPS.setString("FPS : "s + std::to_string(fps));
    textFPS.move(widthScreen - (textFPS.getLocalBounds().width + 15), 0);
}

void Game::refreshFps()
{
    textFPS.setString("Fps: "s + std::to_string(fps));
}



// Score Management
void Game::addPoints(int points)
{
    score += points;
    if (score > bestScore)
        bestScore = score;
    refreshScore();
    refreshBestScore();
}

void Game::refreshScore()
{
    textScore.setString("Score : "s + std::to_string(score));
}

void Game::refreshBestScore()
{
    textBestScore.setString("Best score : "s + std::to_string(bestScore));
}

void Game::loadBestScoreFromFile()
{
    auto file = std::ifstream("bestScores.txt");
    if (file.is_open())
        file >> bestScore;
    else
        bestScore = 0;
    file.close();
}

void Game::recordBestScoreInFile()
{
    if (score == bestScore) {
        bestScore = score;
        auto file = std::ofstream{"bestScores.txt"};
        if (file.is_open())
            file << bestScore;
        else 
            throw std::runtime_error("Impossible. No bestScores file opened.");
        file.close();
    }
}