#include "cabbage.h"

Cabbage::Cabbage()
{
    type = 2;
    age = 0;
    energy = 10;
    range = 1;
    size = 1;
    lastReproduction = 0;
    dead = false;
    reproduction = false;
    eaten = false;

}
void Cabbage::grow()
{
    age++;
    if(energy < 10 && !eaten)
        energy = energy + 1;
    if(size > 5 && lastReproduction > 5 && energy > 4)
    {
        reproduction = true;
    }
    size = 1 + age/2;
    lastReproduction++;

}

void Cabbage::die()
{
    if(age > 30 || energy < 1)
        dead = true;
}
