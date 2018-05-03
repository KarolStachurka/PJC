#include "organism.h"

Organism::Organism()
{

}
Organism::~Organism(){}
void Organism::reproduce()
{
    reproduction = false;
    lastReproduction = 0;
}
bool Organism::isDead()
{
    return dead;
}
int Organism::getAge()
{
    return age;
}
int Organism::getType()
{
    return type;
}

bool Organism::isReproduced()
{
    return reproduction;
}
string Organism::getName()
{
    return name;
}

