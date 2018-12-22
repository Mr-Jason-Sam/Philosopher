#include "philosopher.h"

void Philosopher::run(){
    while (true) {
        takeTbwares();
        putTbwares();
    }
}

void Philosopher::thinking(){
    mStatus = Thinking;
}

void Philosopher::hungry(){
    mStatus = ThinkingHungrily;
}

void Philosopher::takeTbwares(){
    isHasRightFork = true;
    isHasLeftFork = true;

}

void Philosopher::eating(){
    if (isHasLeftFork && isHasRightFork) {
        mStatus = Eating;
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
    mStatus = EatingEnough;
}

void Philosopher::putTbwares(){
    //mutex lock
    isHasRightFork = false;
    isHasLeftFork = false;
    //mutex unlock
}

void Philosopher::operator=(const Philosopher &pher){
    this->mStatus = pher.mStatus;
    this->id = pher.id;
    this->isHasLeftFork = pher.isHasLeftFork;
    this->isHasRightFork = pher.isHasRightFork;
}

bool Philosopher::operator == (const Philosopher &pher) const {
    bool isQueal = false;
    if (this->id == pher.id) {
        isQueal = true;
    }
    return isQueal;
}

void Philosopher::setId(int id){
    this->id = id;
}

int Philosopher::getId(){
    return id;
}

void Philosopher::setRightFork(Fork* rightFork){
    mRightFork = rightFork;
}

Fork* Philosopher::getRightFork(){
    return mRightFork;
}

void Philosopher::setLeftFork(Fork* leftFork){
    mLeftFork = leftFork;
}

Fork* Philosopher::getLeftFork(){
    return mLeftFork;
}

void Philosopher::setStatus(DinerStatus status){
    mStatus = status;
}

DinerStatus Philosopher::getStatus(){
    return mStatus;
}

void Philosopher::setHasLeftFork(bool hasLeftFork){
    isHasLeftFork = hasLeftFork;
}

bool Philosopher::getHasLeftFork(){
    return isHasLeftFork;
}

void Philosopher::setHasRightFork(bool hasRightFork){
    isHasRightFork = hasRightFork;
}

bool Philosopher::getHasRightFork(){
    return isHasRightFork;
}
