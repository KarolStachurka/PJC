#include "slug.h"

Slug::Slug()
{
    type = 2;
    age = 0;
    energy = 10;
    speed = 1;
    lastReproduction = 0;
    hunger = 2;
    dead = false;
    reproduction = false;

}
void Slug::die()
{
    if(energy < 1 || age > 10)
        dead = true;
}
void Slug::grow()
{
    age++;
    energy--;
    lastReproduction++;
    if(lastReproduction > 4 && energy > 6)
        reproduce();
}
