#ifndef FIELD_H
#define FIELD_H
#include "snail.h"
#include "plant.h"

class Field
{
public:
    Field();
    ~Field();

    Plant* plant;
    Snail* snail;

    void setX(int x);
    void setY(int y);
    void setCoordinates(int x, int y);
    int getX();
    int getY();
protected:
    int coordinateX;
    int coordinateY;
};
#endif // FIELD_H
