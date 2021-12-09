#ifndef PLAN_H
#define PLAN_H
#include <cstring>
#include "Item.h"

class Plan : public Item
{
private:
    char _info[1000];
public:
    Plan();

    void setInfo(const char *info)
    {
        strcpy(_info, info);
    };

    char *getInfo(){return _info;};
};

#endif // PLAN_H
