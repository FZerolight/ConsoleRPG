#ifndef __BACKPACK_H__
#define __BACKPACK_H__

#include <vector>
#include "Item.h"

struct BagSlot
{
    ItemBase* item;
    int Num;
};

class Backpack
{
private:
    std::vector<BagSlot>* container;

public:
    Backpack();
    ~Backpack();



};
#endif // __BACKPACK_H__
