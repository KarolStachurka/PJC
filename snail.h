#ifndef SNAIL_H
#define SNAIL_H

#include <ctime>
#include <cstdlib>

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

    static int helixNumber;
    static int slugNumber;
    static int wormNumber;

protected:
    int hunger;
    int speed;
};

#endif // SNAIL_H
