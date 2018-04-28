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
protected:
    string type;
    int hunger;
    int energy;
    int age;
    int speed;
    int lastReproduction;
};

#endif // SNAIL_H
