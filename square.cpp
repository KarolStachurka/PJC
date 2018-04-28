#include "square.h"

Square::Square()
{

}
Square::Square(int x, int y)
{
    this->coordinateX = x;
    this->coordinateY = y;
}
int Square::getX()
{
    return coordinateX;
}
int Square::getY()
{
    return coordinateY;
}
void Square::setX(int x){
    this->coordinateX = x;
}
void Square::setY(int y)
{
    this->coordinateY = y;
}
