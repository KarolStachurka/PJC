#ifndef ORGANISM_H
#define ORGANISM_H

#include "square.h"
class Organism: public Square

{
public:
    Organism();
    virtual void grow() = 0;
    virtual void die() = 0;
};

#endif // ORGANISM_H
