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
    tiredness = true;

}
void Worm::die()
{
    if(energy < 1 || age > 20)
        dead = true;
}
void Worm::eat(int type)
{
    this->energy = 15;
}

void Worm::grow()
{
    age++;
    energy--;
    lastReproduction++;
    hunger = 5 - (age/5);
    if(lastReproduction > 8 && energy > 12)
        reproduction = true;
}

