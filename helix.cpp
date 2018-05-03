#include "helix.h"

Helix::Helix()
{
    type = 1;
    age = 0;
    energy = 10;
    speed = 1;
    lastReproduction = 0;
    hunger = 2;
    dead = false;
    reproduction = false;

}
void Helix::die()
{
    if(energy < 1 || age > 10)
        dead = true;
}
void Helix::grow()
{
    age++;
    energy--;
    lastReproduction++;
    if(lastReproduction > 4 && energy > 6)
        reproduce();
}

