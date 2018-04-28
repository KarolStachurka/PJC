#ifndef SNAIL_H
#define SNAIL_H

#include <iostream>

using namespace std;
struct position{
    int x;
    int y;
};

class Snail
{
public:
    Snail();
    void move();
    void eat();
    void reproduce();
protected:
    string type;
    position snailPosition;
    int hunger;
    int energy;
    int age;
    int speed;
    int lastReproduction;
};

#endif // SNAIL_H
