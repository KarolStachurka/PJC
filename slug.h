#ifndef SLUG_H
#define SLUG_H

#include "snail.h"
class Slug: public Snail
{
public:
    Slug();
    void grow();
    void die();
};

#endif // SLUG_H
