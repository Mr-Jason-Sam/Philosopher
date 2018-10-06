#ifndef WAITER_H
#define WAITER_H

#include <stdio.h>
#include <list>
#include <pthread.h>
#include <iostream>
#include <sys/time.h>
#include "philosopher.h"

#define MAX_PHERS 5

using namespace std;

class waiter;

struct Param{
    philosopher* pher;
    waiter* wer;
    philosopher** phers;
    pthread_mutex_t* mutex;
};

class waiter{
public:
    waiter(int pherCount = MAX_PHERS);
    ~waiter();

    bool readyEating();
    void takeBothForks(philosopher *pher);
    void putBothForks(philosopher *pher);
    void startService();
    void changeThinkToHungty();
    void joinThread();

private:
    static void* task(void* data);
    void getNextFrontPher(philosopher** current,philosopher** next, philosopher** front);
    void checkPhersStatus();

private:
    philosopher** mPhers;
    pthread_mutex_t mutex;
    pthread_cond_t* conds;
    pthread_attr_t attr;
    pthread_t* thread;
    int pherCount;
};

#endif // WAITER_H
