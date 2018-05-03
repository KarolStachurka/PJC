#ifndef GRASS_H
#define GRASS_H

#include "plant.h"

class Grass: public Plant
{
public:
    Grass();
    void grow();
    void die();
};

#endif // GRASS_H
