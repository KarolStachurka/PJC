#ifndef FIELD_H
#define FIELD_H

#include <string>
#include "square.h"

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
    //setters
    void setSnailExistence(bool existence);
    void setPlantExistence(bool existence);
    void setSnailType(string snail);
    void setPlantType(string plant);
    //getters
    bool getSnailExistence();
    bool getPlantExistence();
    string getFieldInfo();
    string getSnailType();
    string getPlantType();


};

#endif // FIELD_H
