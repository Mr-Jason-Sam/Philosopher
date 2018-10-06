#include "waiter.h"

waiter::waiter(int pherCount){
    this->pherCount = pherCount;
    if (readyEating()) {
        cout << "ready eating is success!" << endl;
    } else {
        cout << "ready eating is fail!" << endl;
    }
}

waiter::~waiter() {

    pthread_mutex_lock(&mutex);
    delete[] thread;
    delete[] conds;

    for (int i=0;i<pherCount;i++){
        delete mPhers[i];
//        mPhers[i] = nullptr;
    }
    delete mPhers;
    thread = nullptr;
    conds = nullptr;
    mPhers = nullptr;
    cout << "detele--------------------------" << endl;
    pthread_mutex_unlock(&mutex);

}

bool waiter::readyEating(){
    bool isReady = false;
    mPhers = new philosopher*[pherCount];
    thread = new pthread_t[pherCount];
    conds = new pthread_cond_t[pherCount];
    pthread_mutex_init(&mutex, nullptr);
    pthread_attr_init(&attr);
    for (int i = 0; i < pherCount; i++) {
        pthread_cond_init(&conds[i], nullptr);
        mPhers[i] = new philosopher(i);
        if (mPhers[i] == nullptr) {
            break;
        }
        if (i == pherCount - 1) {
            isReady = true;
        }
    }
    return isReady;
}

void waiter::takeBothForks(philosopher *pher){
    if (pher->getStatus() == EATING || pher->getStatus() == EATING_FINISH ) {
        return;
    }
    philosopher* nextPher = nullptr;
    philosopher* frontPher = nullptr;
    getNextFrontPher(&pher, &nextPher, &frontPher);
    if (nextPher == nullptr || frontPher == nullptr || pher == nullptr) {
        cout << "takeBothForks," << "nextPer is " << nextPher << ",pher is " << pher << ", frontPher is " << frontPher << endl;
        exit(0);
    }

    pthread_mutex_lock(&mutex);
    pher->hungry();
    if (nextPher->getStatus() != EATING &&
        frontPher->getStatus() != EATING &&
        pher->getStatus() == THINKING_HUNGRY) {
        pher->takeTablewares();
        pher->eating();
        cout << pher->getId() << "signal" << endl;
        pthread_cond_signal(&conds[pher->getId()]);
    } else {
        cout << pher->getId() << "wait" << endl;
        pthread_cond_wait(&conds[pher->getId()], &mutex);
    }
    pthread_mutex_unlock(&mutex);
}

void waiter::putBothForks(philosopher *pher){
    if (pher->getStatus() != EATING_FINISH) {
        return;
    }
    cout << "put" << endl;
    philosopher* nextPher = nullptr;
    philosopher* frontPher = nullptr;
    getNextFrontPher(&pher, &nextPher, &frontPher);
    if (nextPher == nullptr || frontPher == nullptr || pher == nullptr) {
        cout << "putBothForks," << "nextPer is " << nextPher << ", pher is " << pher << ", frontPher is " << frontPher << endl;
        exit(0);
    }
    pthread_mutex_lock(&mutex);
    pher->putTablewares();
    pher->hungry();
    pthread_mutex_unlock(&mutex);
    takeBothForks(nextPher);
    takeBothForks(frontPher);
}

void waiter::startService(){
    for (int i = 0 ,ret = 0; i < pherCount; i++) {
        Param* data = new Param();
        data->pher = mPhers[i];
        data->wer = this;
        data->phers = mPhers;
        data->mutex = &mutex;
        if((ret = pthread_create(&thread[i], &attr, task, (void *)data)) == -1) {
            cout <<"init thread is fail:ret " << ret << endl;
        }
    }
}

void waiter::changeThinkToHungty(){
    for (int i = 0; i < pherCount; i++) {
        if (mPhers[i]->getStatus() == THINKING) {
            mPhers[i]->setStatus(THINKING_HUNGRY);
        }
    }
}

void* waiter::task(void* data){
    Param*  param = (Param*)data;
    philosopher* pher = (philosopher*)param->pher;
    waiter* wer = (waiter*)param->wer;
    pthread_mutex_t* mutex= (pthread_mutex_t*)param->mutex;
    philosopher** phers = (philosopher**)param->phers;
    time_t startTime = time(0);
    time_t endTime = time(0);
    int i = 0;
    while (true) {

//        pthread_mutex_lock(mutex);
//        endTime = time(0);
//        if (difftime(endTime, startTime) >= 1) {
//            for (int i = 0; i < MAX_PHERS; i++) {
//                cout << i << "status:"<<phers[i]->getStatus() << "\t";
//            }
//            cout << endl;
//            startTime = endTime;
//        }
//        pthread_mutex_unlock(mutex);
        wer->takeBothForks(pher);
        wer->putBothForks(pher);
        if (i++ == 10)
            break;
    }
    delete[] param;
    return nullptr;
}

void waiter::getNextFrontPher(philosopher** current,philosopher** next, philosopher** front){
    for (int i = 0; i < pherCount; i++) {
        if (**current == *mPhers[i]) {
            *current = mPhers[i];
            *next = mPhers[(i + 1)%pherCount];
            *front = mPhers[(i + pherCount - 1)%pherCount];
        }
    }
}

void waiter::checkPhersStatus(){
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < pherCount; i++) {
        cout << i << "status:"<<mPhers[i]->getStatus() << "\t";
    }
    cout << endl;
    pthread_mutex_unlock(&mutex);
}

void waiter::joinThread() {
    for (int i = 0; i < pherCount; i++) {
        pthread_join(thread[i], nullptr);
    }
}
