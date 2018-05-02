#include "helix.h"

Helix::Helix()
{
    type = "Helix";
    age = 0;
    energy = 10;
    speed = 1;
    lastReproduction = 0;
    hunger = 2;
    dead = false;
    reproduction = false;

}
void Snail::reproduce()
{
    reproduction = true;
    lastReproduction = 0;
}
void Snail::die()
{
    if(energy < 1 || age > 10)
        dead = true;
}
void Snail::grow()
{
    age++;
    energy--;
    lastReproduction++;
    if(lastReproduction > 4 && energy > 6)
        reproduce();
}

