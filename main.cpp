#include <iostream>
#include "waitersence.h"

using namespace std;

int main()
{
//    while(true){
//        Waiter* wer = new Waiter();
//        wer->startService();
//        wer->joinThread();
//        delete wer;
//        wer = nullptr;
//    }
    while (true) {
        WaiterSence* waiterSence = new WaiterSence();
        waiterSence->show();
        delete waiterSence;
        waiterSence = nullptr;
    }

}

