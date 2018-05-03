#include "snail.h"

Snail::Snail()
{

}
bool Snail::isReproduced()
{
    return reproduction;
}
int Snail::getAge()
{
    return age;
}
int Snail::getHunger()
{
    return hunger;
}

int Snail::getSnailType()
{
    return type;
}
void Snail::grow(){}
void Snail::die(){}
bool Snail::getNewPosition(int &x, int &y, int maxX, int maxY)
{
    int rangeInt = 1 + 2*speed;
    int randomX = (-1)*speed + rand()% rangeInt;
    int randomY = (-1)*speed + rand()% rangeInt;
    if(x + randomX >= 0 && y + randomY >= 0 && x + randomX < maxX && y + randomY < maxY)
    {
        x = x + randomX;
        y = y + randomY;
        return true;
    }
    return false;
}
void Snail::eat()
{
    energy = energy + hunger;
}
