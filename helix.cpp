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
void Snail::eat()
{
    energy = energy + 4;
}
void Snail::reproduce()
{
    reproduction = true;
    lastReproduction = 0;
}
void Snail::move(int x, int y)
{
    this->setX(x);
    this->setY(y);
}
void Snail::die()
{
    if(energy < 1 || age > 10)
        dead = true;
}

void Helix::test()
{
    std::cout << this->energy;
}
void Snail::grow()
{
    age++;
    energy--;
    lastReproduction++;
    if(lastReproduction > 4 && energy > 6)
        reproduce();
}
