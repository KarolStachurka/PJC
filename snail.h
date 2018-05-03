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

    void move(int x, int y);
    void eat();
    void reproduce();
    void die();
    void grow();

    bool isReproduced();
    bool isDead();
    int getHunger();
    int getSpeed();
    int getAge();

    void setReproduction(bool reproduction);
    bool getNewPosition(int &x, int &y, int maxX, int maxY);
    int getSnailType();
protected:
    int type;
    int hunger;
    int energy;
    int age;
    int speed;
    int lastReproduction;
    bool reproduction;
    bool dead;
};

#endif // SNAIL_H
