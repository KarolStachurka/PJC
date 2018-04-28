#ifndef HELIX_H
#define HELIX_H

#include "snail.h"

class Helix:public Snail
{
public:
    Helix(position start);
    void eat();
    void move();
    void reproduce();
    void test();
};

#endif // HELIX_H
