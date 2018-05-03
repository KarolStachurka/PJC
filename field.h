#ifndef FIELD_H
#define FIELD_H

#include "square.h"
#include "plant.h"
#include "snail.h"


class Field: public Square
{
private:

public:
    Field();
    ~Field();
    Plant* plant;
    Snail* snail;

    //getters
    string getFieldInfo();


};

#endif // FIELD_H
