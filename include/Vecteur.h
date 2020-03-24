#ifndef VECTEUR_H
#define VECTEUR_H

struct Vecteur
{
    void operator+=(Vecteur const& other);
    void operator-=(Vecteur const& other);
    Vecteur operator*(float coefficient) const;
    float x{0.f};
    float y{0.f};
};

#endif // VECTEUR_H
