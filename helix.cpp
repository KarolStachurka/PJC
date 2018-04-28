#include "helix.h"

Helix::Helix(position start)
{
    type = "Helix";
    snailPosition = start;
    age = 0;
    energy = 10;
    speed = 1;
    lastReproduction = 0;
    hunger = 2;
}
void Helix::eat()
{

}
void Helix::move()
{

}
void Helix::reproduce()
{

}
void Helix::test()
{
    std::cout << this->energy;
}
