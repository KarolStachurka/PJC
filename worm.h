#ifndef WORM_H
#define WORM_H

#include "snail.h"
class Worm: public Snail
{
public:
    Worm();
    void grow();
    void die();
    void eat(int type);
};

#endif // WORM_H
