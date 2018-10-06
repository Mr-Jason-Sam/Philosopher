#include <iostream>
#include "waiter.h"

using namespace std;

int main()
{
    while(true){
        cout<<"begin##########################" <<endl;
        waiter* wer = new waiter();
        wer->startService();
        wer->joinThread();
        delete wer;
        wer = nullptr;
    }

}

