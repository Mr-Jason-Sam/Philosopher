#ifndef TABLEWARE_H
#define TABLEWARE_H

enum TbwareStatus{
    Free,
    Busy
};


class Tableware{
public:
    Tableware();
    virtual ~Tableware();
    virtual void setStatus(TbwareStatus status);
    virtual TbwareStatus getStatus();
private:
    TbwareStatus mStatus;
};

#endif // TABLEWARE_H
