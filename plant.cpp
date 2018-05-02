#include "plant.h"

Plant::Plant()
{

}
bool Plant::isReproduction()
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
