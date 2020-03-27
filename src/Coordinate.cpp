#include "../include/Coordinate.h"
#include <iostream>
#include <cmath>

int Coordinate::widthSpace{0};
int Coordinate::heightSpace{0};

Coordinate::Coordinate() {
    if (widthSpace == 0 || heightSpace == 0) {
        std::cerr << "Warning : a coordinate was created before the space was initialized" << std::endl;
    }
}

Coordinate::Coordinate(float px, float py) : x{px}, y{py} {}

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
}

float Coordinate::calculateDistance(Coordinate const& other) const {
    auto delta = Vecteur{x - other.x, y - other.y};
    return sqrt(delta.x * delta.x + delta.y * delta.y);
}
