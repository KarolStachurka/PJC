#ifndef HELIX_H
#define HELIX_H

#include "snail.h"

class Helix:public Snail
{
public:
    Helix();
    void grow();
    void die();
    void eat(int type);
};

#endif // HELIX_H
