#ifndef FIELD_H
#define FIELD_H
#include "snail.h"
#include "square.h"

class Field:public Square
{
private:
    bool snailExistence = false;
    bool plantExistence = false;

public:
    Field();
    void setCoordinates(int x, int y);
    void setSnailExistence(bool existence);
    void setPlantExistence(bool existence);
    bool getSnailExistence();
    bool getPlantExistence();

};

#endif // FIELD_H
