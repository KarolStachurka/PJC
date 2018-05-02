#ifndef PLANT_H
#define PLANT_H

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "square.h"
#include "field.h"
using namespace std;


class Plant: public Square
{
public:
    Plant();
    void grow();
    void beEaten(int energyLoss);
    void reproduce();
    void die();
    void resetReproducion();

    int getAge();
    bool isReproduction();
    bool isDead();
    bool isEaten();
    bool getNewPosition(int &x, int &y, int maxX, int maxY);
    string getPlantType();
protected:
    string type;
    int size;
    int energy;
    int age;
    int range;
    int lastReproduction;
    bool reproduction;
    bool dead;
    bool eaten;

};

#endif // PLANT_H
