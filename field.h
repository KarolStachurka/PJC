#ifndef FIELD_H
#define FIELD_H

#include <string>
#include "square.h"

using namespace std;

class Field:public Square
{
private:
    bool snailExistence = false;
    bool plantExistence = false;

public:
    Field();
    void setSnailExistence(bool existence);
    void setPlantExistence(bool existence);
    bool getSnailExistence();
    bool getPlantExistence();
    string getFieldInfo();

};

#endif // FIELD_H
