#ifndef THREAD_H
#define THREAD_H

#include <pthread.h>
#include <iostream>

using namespace std;

enum InitStatus{
    InitSuccess = 0,
    InitMutexFail,
    InitCondFail,
    InitAttrFail,
};

enum RuningStatus{
    RunSuccess = 0,
    ThreadCrtFail
};

int const PTHREAD_CREATE_FAIL = -1;

class Thread
{
public:
    Thread();
    virtual ~Thread();
    virtual void run() = 0;
    int join();
    void destory();
    void lock();
    void unlock();
    void wait();
    void notify();

    void setThreadId(size_t threadId);
    size_t getThreadId();
protected:
    InitStatus init();
    int start();
    static void* threadProc(void* data);
private:
    pthread_mutex_t mMutex;
    pthread_cond_t mCond;
    pthread_attr_t mAttr;
    pthread_t mThread;
    size_t mThreadId;
    bool mExit;
};

#endif // THREAD_H
