#include "fork.h"

Fork::Fork(){

}


Fork::~Fork(){

}

void Fork::setStatus(TbwareStatus status){
    mStatus = status;
}

TbwareStatus Fork::getStatus(){
    return mStatus;
}

void Fork::setId(int id){
    this->id = id;
}

int Fork::getId(){
    return id;
}
