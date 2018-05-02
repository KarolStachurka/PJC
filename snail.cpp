#include "snail.h"

Snail::Snail()
{

}
bool Snail::isReproduced()
{
    return reproduction;
}
void Snail::setReproduction(bool reproduction)
{
    this->reproduction = reproduction;
}
int Snail::getAge()
{
    return age;
}
bool Snail::isDead()
{
    return dead;
}
