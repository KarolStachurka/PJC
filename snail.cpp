#include "snail.h"

Snail::Snail()
{

}
Snail::~Snail(){}
int Snail::getHunger()
{
    return hunger;
}

void Snail::grow(){}
void Snail::die(){}
bool Snail::getNewPosition(int &x, int &y, int maxX, int maxY)
{
    int rangeInt = 1 + 2*speed;
    int randomX = (-1)*speed + rand()% rangeInt;
    int randomY = (-1)*speed + rand()% rangeInt;
    if(x + randomX >= 0 && y + randomY >= 0 && x + randomX < maxX && y + randomY < maxY)
    {
        x = x + randomX;
        y = y + randomY;
        tiredness = true;
        return true;
    }
    return false;
}
bool Snail::isTired()
{
    return tiredness;
}

void Snail::eat(int type)
{
    if(type != 3)
        energy = energy + hunger;
    else
        energy++;
}
void Snail::setTired(bool tiredness)
{
    this->tiredness = tiredness;
}

string Snail::getSnailInfo()
{
    string info = "";
    info += "---------------------\n";
    info +=("Typ: " + name + "\n");
    info += ("Wiek: " + to_string(age) + "\n");
    info += ("Żarłoczność: " + to_string(hunger) + "\n");
    info += ("Zdrowie: " + to_string(energy) + "\n");
    info += ("Ostatnio rozmnożył się: " + to_string(lastReproduction) + " tur temu." + "\n");
    return info;
}
