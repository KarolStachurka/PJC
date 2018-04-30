#include "field.h"

Field::Field()
{

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
string Field::getFieldInfo()
{
    string info = "";
    info = "X = " + to_string(this->getX()) + "\n";
    info = info + "Y = " + to_string(this->getY()) + "\n";
    if(this->getSnailExistence())
        info = info + "Snail" + " \n";
    if(this->getPlantExistence())
        info = info + "Plant";
    return info;
}
