#include "helix.h"


Helix::Helix()
{
    name = "Ślimak Winniczek";
    type = 1;
    age = 0;
    energy = 10;
    speed = 1;
    lastReproduction = 0;
    hunger = 4;
    dead = false;
    reproduction = false;
    tiredness = true;

}

void Helix::die()
{
    if(energy < 1 || age > 32)
        dead = true;
}
void Helix::eat(int type)
{
    if(type != 3)
        energy = energy + hunger;
    else
        energy++;
}

void Helix::grow()
{
    age++;
    energy--;
    lastReproduction++;
    if(lastReproduction > 7 && energy > 10)
        reproduction = true;
}

