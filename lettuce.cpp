#include "lettuce.h"

Lettuce::Lettuce()
{
    type = "Lettuce";
    age = 0;
    energy = 10;
    size = 1;
    lastReproduction = 0;
    dead = false;
    reproduction = false;
    eaten = false;
}
void Plant::reproduce()
{

}
void Plant::grow()
{
    age++;
    if(energy < 10 && !eaten)
        energy = energy + 2;
    if(size > 3 && lastReproduction > 3 && energy > 2)
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

bool Plant::isDead()
{
    return dead;
}
