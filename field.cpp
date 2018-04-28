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
void Field::setCoordinates(int x, int y)
{
    this->setX(x);
    this->setY(y);
}
