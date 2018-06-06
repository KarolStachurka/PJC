#include "slug.h"

Slug::Slug()
{

    name = "Ślimak stawowy";
    type = 2;
    age = 0;
    energy = 70;
    speed = 1;
    lastReproduction = 0;
    hunger = 10;
    dead = false;
    reproduction = false;
    tiredness = true;

}
void Slug::die()
{
    if(energy < 1 || age > 60)
    {
        int chance = rand()%10;
        if(chance > 4)
            dead = true;
    }
}
void Slug::eat(int type)
{
    if(type == 1)
        energy = energy + hunger;
    if(type == 2)
        energy = energy + 1.5*hunger;
}

void Slug::grow()
{
    age++;
    energy = energy - 3;
    lastReproduction++;
    if(lastReproduction > 25)
        reproduction = true;
}
