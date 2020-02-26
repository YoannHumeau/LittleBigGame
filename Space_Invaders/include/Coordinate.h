#ifndef COORDINATE_H
#define COORDINATE_H

#include "Vecteur.h"

class Coordinate
{
    public:
        Coordinate();
        Coordinate(float px, float py);

        static void initialiserEspace(int with, int height);
        static inline int getWidthSpace() {return widthSpace;};
        static inline int getHeightSpace() {return heightSpace;};
        inline float getX() const {return x;};
        inline float getY() const {return y;};

        void operator+= (Vecteur const& vecteur);
        float calculateDistance(Coordinate const& other) const;

    private:
        void recalculate();

        float x{widthSpace/6.f};
        float y{heightSpace/2.f};

        static int widthSpace;
        static int heightSpace;
};

#endif // COORDINATE_H
