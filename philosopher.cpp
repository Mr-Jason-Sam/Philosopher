#include "philosopher.h"

void philosopher::operator=(const philosopher &pher){
    this->mStatus = pher.mStatus;
    this->id = pher.id;
    this->isHasLeftFork = pher.isHasLeftFork;
    this->isHasRightFork = pher.isHasRightFork;
}

bool philosopher::operator == (const philosopher &pher) const {
    bool isQueal = false;
    if (this->id == pher.id) {
        isQueal = true;
    }
    return isQueal;
}

void philosopher::thinking(){
    mStatus = THINKING;
}

void philosopher::hungry(){
    mStatus = THINKING_HUNGRY;
}

void philosopher::takeTablewares(){
    isHasRightFork = true;
    isHasLeftFork = true;
//        eating();

}

void philosopher::eating(){
    if (isHasLeftFork && isHasRightFork) {
        mStatus = EATING;
    }
    //sleep(1);
//    time_t startTime = time(0);
//    time_t endTime = time(0);
//    while (true) {
//        endTime = time(0);
//        if (difftime(endTime, startTime) > 0) {
//            break;
//        }
//    }
    mStatus = EATING_FINISH;
}

void philosopher::putTablewares(){
    //mutex lock
    isHasRightFork = false;
    isHasLeftFork = false;
    //mutex unlock
}
