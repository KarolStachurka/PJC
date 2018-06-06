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
