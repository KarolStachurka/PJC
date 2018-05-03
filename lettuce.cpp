#include "lettuce.h"

Lettuce::Lettuce()
{
    type = 1;
    age = 0;
    energy = 10;
    range = 1;
    size = 1;
    lastReproduction = 0;
    dead = false;
    reproduction = false;
    eaten = false;
}

void Lettuce::grow()
{
    age++;
    if(energy < 10 && !eaten)
        energy = energy + 2;
    if(size > 3 && lastReproduction > 5 && energy > 4)
    {
        reproduction = true;
    }
    size = 1 + age/2;
    lastReproduction++;

}
void Lettuce::die()
{
    if(age > 15 || energy < 1)
        dead = true;
}
