#ifndef DINER_H
#define DINER_H

#include "tableware.h"
#include "waiter2.h"

enum DinerStatus{
    Eating,
    EatingEnough,
    Thinking,
    ThinkingHungrily
};

class Diner
{
public:
    Diner();
    virtual ~Diner();
    virtual void eating() = 0;
    virtual void hungry() = 0;
    virtual void takeTbwares() = 0;
    virtual void putTbwares() = 0;
};

#endif // DINER_H
