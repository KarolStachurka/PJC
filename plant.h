#ifndef PLANT_H
#define PLANT_H

#include <iostream>
#include "square.h"
using namespace std;


class Plant:public Square
{
public:
    Plant();
    void grow();
    void beEaten();
    void reproduce();
    bool getReproduction();
    void resetReproducion();
protected:
    string type;
    int size;
    int energy;
    int age;
    int lastReproduction;
    bool reproduction;
};

#endif // PLANT_H
