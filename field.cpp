#include "field.h"

Field::Field()
{
    snailExistence = false;
    plantExistence = false;
    snailType = "";
    plantType = "";
    snail = NULL;
    plant = NULL;
}
Field::~Field()
{
    snail = NULL;
    plant = NULL;
}

void Field::setSnailExistence(bool existence)
{
    this->snailExistence = existence;
}
void Field::setPlantExistence(bool existence)
{
    this->plantExistence = existence;
}

bool Field::getSnailExistence()
{
    return snailExistence;
}
bool Field::getPlantExistence()
{
    return plantExistence;
}
string Field::getSnailType()
{
    return snailType;
}
string Field::getPlantType()
{
    return plantType;
}
void Field::setPlantType(string plantType)
{
    this->plantType = plantType;
}
void Field::setSnailType(string snailType)
{
    this->snailType = snailType;
}

string Field::getFieldInfo()
{
    string info = "";
    info = "X = " + to_string(this->getX()) + "\n";
    info = info + "Y = " + to_string(this->getY()) + "\n";
    if(this->getSnailExistence())
        info = info + "Snail" + snailType + " \n";
    if(this->getPlantExistence())
        info = info + "Plant" + plantType;
    return info;
}
