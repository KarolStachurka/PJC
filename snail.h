#ifndef SNAIL_H
#define SNAIL_H

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "square.h"
#include "organism.h"

using namespace std;

class Snail: public Organism
{
public:
    Snail();

    void eat();
    void die();
    void grow();

    bool isReproduced();
    int getHunger();
    int getSpeed();
    int getAge();

    bool getNewPosition(int &x, int &y, int maxX, int maxY);
    int getSnailType();
protected:
    int hunger;
    int speed;
};

#endif // SNAIL_H
