#ifndef ORGANISM_H
#define ORGANISM_H

#include "square.h"

using namespace std;

class Organism: public Square

{
public:
    Organism();
    virtual ~Organism();
    virtual void grow() = 0;
    virtual void die() = 0;
    virtual bool getNewPosition(int &x, int &y, int maxX, int maxY) = 0;
    void reproduce();

    int getAge();
    int getType();
    string getName();
    bool isReproduced();
    bool isDead();

protected:
    int energy;
    int age;
    int lastReproduction;
    int type;

    string name;

    bool dead;
    bool reproduction;

};

#endif // ORGANISM_H
