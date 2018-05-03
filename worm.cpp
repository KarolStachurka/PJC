#include "worm.h"

Worm::Worm()
{
    type = 3;
    age = 0;
    energy = 15;
    speed = 2;
    lastReproduction = 0;
    hunger = 2;
    dead = false;
    reproduction = false;

}
void Worm::die()
{
    if(energy < 1 || age > 20)
        dead = true;
}
void Worm::grow()
{
    age++;
    energy--;
    lastReproduction++;
    if(lastReproduction > 4 && energy > 5)
        reproduction = true;
}

