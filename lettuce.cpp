#include "lettuce.h"


Lettuce::Lettuce()
{

    name = "Sałata";
    type = 1;
    age = 0;
    energy = 20;
    range = 2;
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
    if(size > 3 && lastReproduction > 4 && energy > 4)
    {
        reproduction = true;
    }
    size = 1 + age/2;
    lastReproduction++;

}
void Lettuce::die()
{
    if(age > 20 || energy < 1)
        dead = true;
}
