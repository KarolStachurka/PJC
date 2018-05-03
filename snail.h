#ifndef SNAIL_H
#define SNAIL_H

#include <ctime>
#include <cstdlib>

#include "square.h"
#include "organism.h"


class Snail: public Organism
{
public:
    Snail();
    ~Snail();
    void eat();
    void die();
    void grow();
    bool getNewPosition(int &x, int &y, int maxX, int maxY);

    //getters
    int getHunger();
    int getSpeed();
    string getSnailInfo();

protected:
    int hunger;
    int speed;
};

#endif // SNAIL_H
