#ifndef FIELD_H
#define FIELD_H

#include <string>
#include "square.h"
#include "plant.h"
#include "snail.h"

using namespace std;

class Field: public Square
{
private:
    bool snailExistence;
    bool plantExistence;
    string snailType;
    string plantType;


public:
    Field();
    ~Field();
    Plant* plant;
    Snail* snail;
    //setters
    void setSnailExistence(bool existence);
    void setPlantExistence(bool existence);
    void setSnailType(string snailType);
    void setPlantType(string plantType);
    //getters
    bool getSnailExistence();
    bool getPlantExistence();
    string getFieldInfo();
    string getSnailType();
    string getPlantType();


};

#endif // FIELD_H
