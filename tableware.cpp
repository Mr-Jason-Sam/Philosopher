#include "tableware.h"

Tableware::Tableware(){

}

Tableware::~Tableware(){

}

void Tableware::setStatus(TbwareStatus status){
    mStatus = status;
}

TbwareStatus Tableware::getStatus(){
    return mStatus;
}
