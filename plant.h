#ifndef PLANT_H
#define PLANT_H

#include <ctime>
#include <cstdlib>

#include "organism.h"


class Plant: public Organism
{
public:
    Plant();
    ~Plant();

    void beEaten(int energyLoss);
    bool getNewPosition(int &x, int &y, int maxX, int maxY);
    void grow();
    void die();

    //getters
    bool isEaten();
    int getSize();
    string getPlantInfo();

protected:

    int size;
    int range;

    bool eaten;

};

#endif // PLANT_H
