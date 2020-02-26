#include "Vecteur.h"

void Vecteur::operator+=(Vecteur const& other) {
    x += other.x;
    y += other.y;
}

void Vecteur::operator-=(Vecteur const& other) {
    x -= other.x;
    y -= other.y;
}

Vecteur Vecteur::operator*(float coefficient) const {
    return Vecteur{x * coefficient, y * coefficient};
}
