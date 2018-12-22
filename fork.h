#ifndef FORK_H
#define FORK_H

#include "tableware.h"
#define MAX_FORKS 5

class Fork : public Tableware{
public:
    Fork();
    virtual ~Fork();
    virtual void setStatus(TbwareStatus status);
    virtual TbwareStatus getStatus();
    void setId(int id);
    int getId();
private:
    int id;
    TbwareStatus mStatus;
};

#endif // FORK_H
