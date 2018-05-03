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
void Snail::move(int x, int y)
{
    this->setX(x);
    this->setY(y);
}
int Snail::getSnailType()
{
    return type;
}
bool Snail::getNewPosition(int &x, int &y, int maxX, int maxY)
{
    int rangeInt = 1 + 2*speed;
    int randomX = (-1)*speed + rand()% rangeInt;
    int randomY = (-1)*speed + rand()% rangeInt;
    if(x + randomX >= 0 && y + randomY >= 0 && x + randomX < maxX && y + randomY < maxY)
    {
        x = x + randomX;
        y = y + randomY;
        return true;
    }
    return false;
}
void Snail::eat()
{
    energy = energy + hunger;
}
