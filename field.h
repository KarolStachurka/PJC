#ifndef FIELD_H
#define FIELD_H
#include "snail.h"
#include "plant.h"
#include "square.h"

class Field:public Square
{
public:
    Field();
    ~Field();
    Plant* plant;
    Snail* snail;



};
#endif // FIELD_H
