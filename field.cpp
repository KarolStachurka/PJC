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
int Field::getX()
{
    return coordinateX;
}
int Field::getY()
{
    return coordinateY;
}
void Field::setCoordinates(int x, int y)
{
    this->coordinateX = x;
    this->coordinateY = y;
}
Plant* Field::getPlant()
{
    return plant;
}
Snail* Field::getSnail()
{
    return snail;
}
void Field::setPlant(Plant *plant)
{
    this->plant = plant;
}
void Field::setSnail(Snail *snail)
{
    this->snail = snail;
}
