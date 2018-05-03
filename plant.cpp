#include "plant.h"

Plant::Plant() {}
Plant::~Plant() {}
void Plant::grow()
{
    age++;
}
void Plant::die()
{
    dead = true;
}

bool Plant::getNewPosition(int &x, int &y, int maxX, int maxY)
{
    int rangeInt = 1 + 2*range;
    int randomX = (-1)*range + rand()% rangeInt;
    int randomY = (-1)*range + rand()% rangeInt;
    if(x + randomX >= 0 && y + randomY >= 0 && x + randomX < maxX && y + randomY < maxY)
    {
        x = x + randomX;
        y = y + randomY;
        return true;
    }
    return false;
}
void Plant::beEaten(int energyLoss)
{
    energy = energy - energyLoss;
    eaten = true;
}
string Plant::getPlantInfo()
{
    string info = "";
    info += "---------------------\n";
    info +=("Typ: " + name + "\n");
    info += ("Wiek: " + to_string(age) + "\n");
    info += ("Rozmiar: " + to_string(size) + "\n");
    info += ("Zdrowie: " + to_string(energy) + "\n");
    info += ("Ostatnio rozmnożył się: " + to_string(lastReproduction) + " tur temu." + "\n");
    return info;
}
