#include "../include/Coordinate.h"
#include <iostream>
#include <cmath>

int Coordinate::widthSpace{0};
int Coordinate::heightSpace{0};

Coordinate::Coordinate() {
    if (widthSpace != 0 || heightSpace != 0) {
        std::cerr << "Warning : a coordinate was created before the space was initialized" << std::endl;
    }
}

Coordinate::Coordinate(float px, float py) : x{px}, y{py}
{
    recalculate();
}

void Coordinate::initialiserEspace(int width, int height)
{
    if (widthSpace != 0 || heightSpace != 0) {
        std::cerr << "Warning : the space already initialized" << std::endl;
    }
    widthSpace = width;
    heightSpace = height;
}

void Coordinate::operator+= (Vecteur const& vecteur)
{
    x += vecteur.x;
    y += vecteur.y;
    recalculate();
}

void Coordinate::recalculate() {
    // Penser à ajouter à x la moitier de la largeur du sprite
    //auto halfSpriteX = sprite.getLocalBounds().width / 2.f;
    // Penser à ajouter à y la moitier de la hauteur du sprite
    //auto halfSpriteY = sprite.getLocalBounds().height / 2.f;

    while (x > widthSpace) {x = widthSpace;}
    while (x < 0) {x = 0;}
    while (y > heightSpace) {y = heightSpace;}
    while (y < 0) {y = 0;}
}

float Coordinate::calculateDistance(Coordinate const& other) const {
    auto delta = Vecteur{x - other.x, y - other.y};
    return sqrt(delta.x * delta.x + delta.y * delta.y);
}
