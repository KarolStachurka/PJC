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
}
void Plant::reproduce()
{

}
void Plant::grow()
{
    age++;
    if(energy < 10)
        energy = energy + 2;
    if(age > 2 && lastReproduction > 2)
    {
        reproduction = true;
    }
    if(age > 6 || energy < 0)
        dead = true;
    size = 1 + age/2;
    lastReproduction++;

}
bool Plant::isDead()
{
    return dead;
}
