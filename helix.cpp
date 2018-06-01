#include "helix.h"

int Snail::helixNumber = 0;

Helix::Helix()
{
    helixNumber++;

    name = "Ślimak Winniczek";
    type = 1;
    age = 0;
    energy = 12;
    speed = 1;
    lastReproduction = 0;
    hunger = 2;
    dead = false;
    reproduction = false;

}
Helix::~Helix()
{
    helixNumber--;
}

void Helix::die()
{
    if(energy < 1 || age > 20)
        dead = true;
}
void Helix::grow()
{
    age++;
    energy--;
    lastReproduction++;
    if(lastReproduction > 5 && energy > 5)
        reproduction = true;
}

