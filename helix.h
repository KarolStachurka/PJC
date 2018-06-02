#ifndef HELIX_H
#define HELIX_H

#include "snail.h"

class Helix:public Snail
{
public:
    Helix();
    void grow();
    void die();
};

#endif // HELIX_H
