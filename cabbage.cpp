#include "cabbage.h"

int Plant::cabbageNumber = 0;

Cabbage::Cabbage()
{
    cabbageNumber++;

    name = "Kapusta";
    type = 2;
    age = 0;
    energy = 50;
    range = 1;
    size = 1;
    lastReproduction = 0;
    dead = false;
    reproduction = false;
    eaten = false;

}
Cabbage::~Cabbage()
{
    cabbageNumber--;
}

void Cabbage::grow()
{
    age++;
    if(energy < 10 && !eaten)
        energy = energy + 1;
    if(size > 7 && lastReproduction > 10 && energy > 0)
    {
        reproduction = true;
    }
    size = 1 + age/2;
    lastReproduction++;

}

void Cabbage::die()
{
    if(age > 40 || energy < 1)
        dead = true;
}
