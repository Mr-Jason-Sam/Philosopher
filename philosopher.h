#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include "diner.h"
#include "thread.h"
#include "fork.h"
#define MAX_PHERS 5

class Philosopher : public Diner, public Thread{
public:
    Philosopher(int id, Fork* leftFork, Fork* rightFork){
        this->id = id;
        mStatus = Thinking;
        mLeftFork = leftFork;
        mRightFork = rightFork;
        isHasLeftFork = false;
        isHasRightFork = false;
    }
    Philosopher(){}
    virtual ~Philosopher(){

    }
    void thinking();
    virtual void takeTbwares();
    virtual void eating();
    virtual void hungry();
    virtual void putTbwares();

    virtual void run();

    void operator = (const Philosopher &pher);
    bool operator == (const Philosopher &pher)const;

    void setId(int id);
    int getId();
    void setStatus(DinerStatus status);
    DinerStatus getStatus();
    void setRightFork(Fork*);
    Fork* getRightFork();
    void setLeftFork(Fork*);
    Fork* getLeftFork();
    void setHasLeftFork(bool hasLeftFork);
    bool getHasLeftFork();
    void setHasRightFork(bool hasRightFork);
    bool getHasRightFork();

private:
    int id;
    DinerStatus mStatus;
    Fork* mLeftFork;
    Fork* mRightFork;
    bool isHasLeftFork;
    bool isHasRightFork;
};

#endif // PHILOSOPHER_H
