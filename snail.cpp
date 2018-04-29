#include "snail.h"

Snail::Snail()
{

}
bool Snail::isReproduced()
{
    return reproduction;
}
bool Snail::isDead()
{
    return dead;
}
void Snail::setReproduction(bool reproduction)
{
    this->reproduction = reproduction;
}
