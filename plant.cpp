#include "plant.h"

Plant::Plant()
{

}
bool Plant::getReproduction()
{
    return reproduction;
}
void Plant::resetReproducion()
{
    lastReproduction = 0;
}
int Plant::getAge()
{
    return age;
}
void Plant::die()
{
    if(age > 8 || energy < 1)
        dead = true;
}
