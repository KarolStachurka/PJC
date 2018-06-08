#include "worm.h"

Worm::Worm()
{
    name = "Ślinik Luzytański";
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
    if(energy < 1 || age > 25)
        dead = true;
}
void Worm::eat(int type)
{
    if(type == 0)
        this->energy = 15;
}

void Worm::grow()
{
    age++;
    energy--;
    lastReproduction++;
    hunger = 5 - (age/5);
    if(lastReproduction > 3 && energy > 13)
        reproduction = true;
}

