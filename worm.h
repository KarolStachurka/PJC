#ifndef WORM_H
#define WORM_H

#include "snail.h"
class Worm: public Snail
{
public:
    Worm();
    ~Worm();
    void grow();
    void die();
};

#endif // WORM_H
