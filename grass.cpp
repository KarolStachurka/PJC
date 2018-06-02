#include "grass.h"


Grass::Grass()
{

    name = "trawa";
    type = 3;
    age = 0;
    energy = 5;
    range = 5;
    size = 1;
    lastReproduction = 0;
    dead = false;
    reproduction = false;
    eaten = false;
}

void Grass::grow()
{
    age++;
    if(energy < 10 && !eaten)
        energy = energy + 1;
    if(size > 5 && lastReproduction > 2 && energy > 4)
    {
        reproduction = true;
    }
    size = 1 + age/2;
    lastReproduction++;

}

void Grass::die()
{
    if(age > 50 || energy < 1)
        dead = true;
}

