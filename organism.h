#ifndef ORGANISM_H
#define ORGANISM_H

#include "square.h"
class Organism: public Square

{
public:
    Organism();
    virtual void grow() = 0;
    virtual void die() = 0;
    void reproduce();
    bool isDead();
protected:
    int energy;
    int age;
    int lastReproduction;
    int type;

    bool dead;
    bool reproduction;

};

#endif // ORGANISM_H
