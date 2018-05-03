#include "field.h"

Field::Field()
{
    snail = NULL;
    plant = NULL;
}
Field::~Field()
{
    snail = NULL;
    plant = NULL;
}

string Field::getFieldInfo()
{
    string info = "";
    info = "X = " + to_string(this->getX()) + "\n";
    info = info + "Y = " + to_string(this->getY()) + "\n";
    return info;
}
