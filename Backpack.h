#ifndef __BACKPACK_H__
#define __BACKPACK_H__

#include <vector>
#include <string>
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
    int MaxSlot;
    std::string ErrorLog;

    bool _sortbyitemid(const BagSlot& v1, const BagSlot& v2);

public:
    Backpack(int maxslot);
    ~Backpack();
    bool add(BagSlot item);
    std::string getLog();
    void SortBag();
    friend std::ostream& operator<< (std::ostream& s, Backpack* obj);
    BagSlot operator[] (int index);
    BagSlot operator[] (std::string key);

};
#endif // __BACKPACK_H__
