#include "thread.h"

Thread::Thread(){
    int resCode;
    if((resCode = init()) == InitSuccess){
        cout << "init thread is success!" << endl;
    } else{
        cout << "fail to init thread,the error code is" << resCode << endl;
    }
}

Thread::~Thread(){

}

InitStatus Thread::init(){
    InitStatus status = InitSuccess;
    pthread_mutex_init(&mMutex, nullptr);
    pthread_cond_init(&mCond, nullptr);
    pthread_attr_init(&mAttr);
    return status;
}

int Thread::start() {
    RuningStatus status = RunSuccess;
    int ret = PTHREAD_CREATE_FAIL;

    if ((ret = pthread_create(&mThread, &mAttr, threadProc, static_cast<void*>(this))) != PTHREAD_CREATE_FAIL) {
        cout << "pthread create is fail, code is " <<  ret << endl;
        return ret;
    }
    setThreadId(static_cast<size_t>(pthread_self()));
    cout << getThreadId() << "  is starting " << endl;
    return status;
}

void Thread::lock() {
    pthread_mutex_lock(&mMutex);
}

void Thread::unlock() {
    pthread_mutex_unlock(&mMutex);
}

void Thread::wait() {
    pthread_cond_wait(&mCond, &mMutex);
}

void Thread::notify(){
    pthread_cond_signal(&mCond);
}

int Thread::join() {
    mExit = true;
    notify();
    int ret = pthread_join(mThread, nullptr);
    return ret;
}

void Thread::destory() {
    if (!mExit) {
        join();
    }
    pthread_cond_destroy(&mCond);
    pthread_attr_destroy(&mAttr);
}

void* Thread::threadProc(void *data) {
    Thread* pthis = static_cast<Thread*>(data);
    while (!pthis->mExit) {
        pthis->run();
    }
    pthread_exit(pthis);
}

void Thread::setThreadId(size_t threadId){
    mThreadId = threadId;
}

size_t Thread::getThreadId(){
    return mThreadId;
}
