#include "lettuce.h"

Lettuce::Lettuce()
{
    type = "Lettuce";
    age = 0;
    energy = 10;
    range = 1;
    size = 1;
    lastReproduction = 0;
    dead = false;
    reproduction = false;
    eaten = false;
}

void Plant::reproduce()
{

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

void Plant::grow()
{
    age++;
    if(energy < 10 && !eaten)
        energy = energy + 2;
    if(size > 3 && lastReproduction > 3 && energy > 4)
    {
        reproduction = true;
    }
    size = 1 + age/2;
    lastReproduction++;

}

void Plant::beEaten(int energyLoss)
{
    energy = energy - 5;
    eaten = true;
}

void Plant::die()
{
    if(age > 10 || energy < 1)
        dead = true;
}

bool Plant::isDead()
{
    return dead;
}
