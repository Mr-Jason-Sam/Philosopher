#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

enum PHILOSOPHER_STATUS{
    THINKING,
    EATING,
    THINKING_HUNGRY,
    EATING_FINISH
};

class philosopher{
public:
    philosopher(int id){
        this->id = id;
        mStatus = THINKING;
        isHasLeftFork = false;
        isHasRightFork = false;
    }
    philosopher(){}
    ~philosopher(){

    }
    void thinking();
    void takeTablewares();
    void eating();
    void hungry();
    void putTablewares();

    void operator = (const philosopher &pher);
    bool operator == (const philosopher &pher)const;

    void setId(int id){
        this->id = id;
    }

    int getId(){
        return id;
    }

    void setStatus(PHILOSOPHER_STATUS status){
        mStatus = status;
    }

    PHILOSOPHER_STATUS getStatus(){
        return mStatus;
    }

    void setHasLeftFork(bool hasLeftFork){
        isHasLeftFork = hasLeftFork;
    }

    bool getHasLeftFork(){
        return isHasLeftFork;
    }

    void setHasRightFork(bool hasRightFork){
        isHasRightFork = hasRightFork;
    }

    bool getHasRightFork(){
        return isHasRightFork;
    }
private:
    int id;
    PHILOSOPHER_STATUS mStatus;
    bool isHasLeftFork;
    bool isHasRightFork;
};

#endif // PHILOSOPHER_H
