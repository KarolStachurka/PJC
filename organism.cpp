#include "organism.h"

Organism::Organism()
{

}
void Organism::reproduce()
{
    reproduction = false;
    lastReproduction = 0;
}
bool Organism::isDead()
{
    return dead;
}
