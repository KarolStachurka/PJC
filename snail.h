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
    void eat(int type);
    void die();
    void grow();
    bool getNewPosition(int &x, int &y, int maxX, int maxY);

    //getters
    int getHunger();
    int getSpeed();
    bool isTired();
    string getSnailInfo();

    void setTired(bool tiredness);

protected:
    int hunger;
    int speed;
    bool tiredness;
};

#endif // SNAIL_H
