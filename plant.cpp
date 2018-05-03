#include "plant.h"

Plant::Plant()
{

}
bool Plant::isReproduction()
{
    return reproduction;
}
void Plant::resetReproducion()
{
    lastReproduction = 0;
}
void Plant::grow()
{
    age++;
}
void Plant::die()
{
    dead = true;
}

int Plant::getAge()
{
    return age;
}
bool Plant::getNewPosition(int &x, int &y, int maxX, int maxY)
{
    int rangeInt = 1 + 2*range;
    int randomX = (-1)*range + rand()% rangeInt;
    int randomY = (-1)*range + rand()% rangeInt;
    if(x + randomX >= 0 && y + randomY >= 0 && x + randomX < maxX && y + randomY < maxY)
    {
        x = x + randomX;
        y = y + randomY;
        return true;
    }
    return false;
}
bool Plant::isDead()
{
    return dead;
}
int Plant::getPlantType()
{
    return type;
}
void Plant::beEaten(int energyLoss)
{
    energy = energy - energyLoss;
    eaten = true;
}
