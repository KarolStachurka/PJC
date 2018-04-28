#include "helix.h"

Helix::Helix()
{
    type = "Helix";
    age = 0;
    energy = 10;
    speed = 1;
    lastReproduction = 0;
    hunger = 2;
}
void Snail::eat()
{

}
void Snail::reproduce()
{

}
void Snail::move(int x, int y)
{
    this->setX(x);
    this->setY(y);
    energy--;
    age++;
}

void Helix::test()
{
    std::cout << this->energy;
}
