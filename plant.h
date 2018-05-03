#ifndef PLANT_H
#define PLANT_H

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "organism.h"
using namespace std;


class Plant: public Organism
{
public:
    Plant();
    void beEaten(int energyLoss);
    void resetReproducion();
    void grow();
    void die();
    int getAge();
    bool isReproduction();
    bool isDead();
    bool isEaten();
    bool getNewPosition(int &x, int &y, int maxX, int maxY);
    int getPlantType();

protected:
    int type;
    string typeName;
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
