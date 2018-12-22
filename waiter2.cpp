#include "waiter2.h"

Waiter2::Waiter2(int id, Fork** forks){
    setId(id);
    setFork(forks);
}

Waiter2::Waiter2(){

}

Waiter2::~Waiter2(){

}

void Waiter2::run(){

}

bool Waiter2::allowTakeTbwares(int forkId){
    bool isAllow = false;
    if(checkTbwares(forkId)){
        isAllow = true;
    } else{
        isAllow = false;
    }
    return isAllow;
}

bool Waiter2::checkTbwares(int pherId){
    bool isRLFree = false;;
    Fork* pherLFork = forks[pherId];
    Fork* pherRFork = forks[(pherId+MAX_FORKS-1)%MAX_FORKS];
    if (pherLFork->getStatus() == Free && pherRFork->getStatus() == Free){
        pherLFork->setStatus(Busy);
        pherRFork->setStatus(Busy);
        isRLFree = true;
    } else {
        isRLFree = false;
    }
    return isRLFree;
}

void Waiter2::setFork(Fork** forks){
    this->forks = forks;
}

Fork** Waiter2::getFork(){
    return forks;
}

void Waiter2::setId(int id){
    this->id = id;
}

int Waiter2::getId(){
    return id;
}
