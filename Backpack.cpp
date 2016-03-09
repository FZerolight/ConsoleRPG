#include "Backpack.h"

using namespace std;

Backpack::Backpack(int maxslot)
{
    this->MaxSlot = maxslot;
    this->ErrorLog = "All Green";
    this->container = new vector<BagSlot>();
}

Backpack::~Backpack()
{
    //
}

bool Backpack::add(BagSlot item)
{
    int num = container->size();
    if (num >= MaxSlot)
    {
        ErrorLog = "Backpack Full";
        return false;
    }
    else
    {
        container->push_back(item);
        return true;
    }
}

string Backpack::getLog()
{
    return ErrorLog;
}

void Backpack::SortBag()
{
    sort(container->begin(), container->end(), this->_sortbyitemid);
}

bool Backpack::_sortbyitemid(const BagSlot& v1, const BagSlot& v2)
{
    return v1.Num > v2.Num;
}

ostream& operator<< (ostream& s, Backpack* obj)
{
    s << "==========Backpack==========" << endl;
    for (BagSlot i:obj->container)
    {
        cout << i.item << endl;
    }
}
