#ifndef SNAIL_H
#define SNAIL_H

#include <iostream>
#include "square.h"
using namespace std;

class Snail:public Square
{
public:
    Snail();
    void move(int x, int y);
    void eat();
    void reproduce();
    bool isReproduced();
    bool isDead();
    void die();
    void grow();
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
