#include "cabbage.h"


Cabbage::Cabbage()
{

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
    if(age > 50 || energy < 1)
    {
        int chance = rand()%10;
        if(chance > 6)
            dead = true;
    }
}
