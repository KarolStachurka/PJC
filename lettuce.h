#ifndef LETTUCE_H
#define LETTUCE_H

#include "plant.h"

class Lettuce: public Plant
{
public:
    Lettuce();
    ~Lettuce();
    void grow();
    void die();
};

#endif // LETTUCE_H
