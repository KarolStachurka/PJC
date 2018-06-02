#ifndef CABBAGE_H
#define CABBAGE_H

#include "plant.h"

class Cabbage: public Plant
{
public:
    Cabbage();
    void grow();
    void die();

};

#endif // CABBAGE_H
