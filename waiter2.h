#ifndef WAITER2_H
#define WAITER2_H

#include "thread.h"
#include "fork.h"

class Waiter2 : public Thread{
public:
    Waiter2(int id, Fork** forks);
    Waiter2();
    virtual ~Waiter2();
    virtual void run();

    bool allowTakeTbwares(int forkId);

    void setId(int id);
    int getId();
    void setFork(Fork**);
    Fork** getFork();
private:
    bool checkTbwares(int forkId);
private:
    int id;
    Fork** forks;
};

#endif // WAITER2_H
