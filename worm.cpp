#include "worm.h"

Worm::Worm()
{
    name = "Ślimak nagi";
    type = 3;
    age = 0;
    energy = 15;
    speed = 2;
    lastReproduction = 0;
    hunger = 5;
    dead = false;
    reproduction = false;

}
void Worm::die()
{
    if(energy < 1 || age > 25)
        dead = true;
}
void Worm::grow()
{
    age++;
    energy--;
    lastReproduction++;
    hunger = 5 - (age/5);
    if(lastReproduction > 8 && energy > 7)
        reproduction = true;
}

