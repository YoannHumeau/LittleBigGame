#ifndef RESOURCE_H
#define RESOURCE_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

struct Resource
{
        sf::Sound sound{};
        sf::Sprite sprite{};
};

#endif