#include "slug.h"

Slug::Slug()
{

    name = "Ślimak stawowy";
    type = 2;
    age = 0;
    energy = 50;
    speed = 1;
    lastReproduction = 0;
    hunger = 2;
    dead = false;
    reproduction = false;
    tiredness = true;

}
void Slug::die()
{
    if(energy < 1 || age > 40)
        dead = true;
}
void Slug::grow()
{
    age++;
    energy--;
    lastReproduction++;
    if(lastReproduction > 20)
        reproduction = true;
}
