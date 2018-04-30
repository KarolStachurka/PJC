#ifndef SNAIL_H
#define SNAIL_H

#include <iostream>
#include "square.h"
#include "field.h"
using namespace std;

class Snail:public Square
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

    void setReproduction(bool reproduction);
protected:
    string type;
    int hunger;
    int energy;
    int age;
    int speed;
    int lastReproduction;
    bool reproduction;
    bool dead;
};

#endif // SNAIL_H
