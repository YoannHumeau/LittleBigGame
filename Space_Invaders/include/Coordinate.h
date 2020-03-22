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

        static int widthSpace;
        static int heightSpace;
        
        float x{0};
        float y{0};
};

#endif // COORDINATE_H
