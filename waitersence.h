#ifndef WAITERSENCE_H
#define WAITERSENCE_H

#include "sence.h"
#include "fork.h"
#include "philosopher.h"
#include "waiter2.h"

class WaiterSence : public Sence{
public:
    WaiterSence();
    virtual ~WaiterSence();
    virtual void show();
};

#endif // WAITERSENCE_H
