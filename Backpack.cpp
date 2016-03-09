#include "Backpack.h"
#include "Common.h"
#include <algorithm>

using namespace std;

Backpack::Backpack(int maxslot)
{
    this->MaxSlot = maxslot;
    this->ErrorLog = "All Green";
    this->container = new vector<BagSlot>();
    cout << "A backpack is created" << endl;
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

/*void Backpack::SortBag()
{
    std::sort((*container).begin(), (*container).end(), this->_sortbyitemid);
}*/

bool Backpack::_sortbyitemid(const BagSlot& v1, const BagSlot& v2)
{
    return v1.Num > v2.Num;
}

ostream& operator<< (ostream& s, Backpack* obj)
{
    if (obj->container->empty())
    {
        s << "The backpack is empty" << endl;
    }
    else
    {
        s << "==========Backpack==========" << endl;
        for (BagSlot i:(*(obj->container)))
        {
            switch (i.Item->getItemID())
            {
            case Item_HP:
                {
                    auto output = (HealthPotion*)(i.Item);
                    s << output << endl;
                    break;
                }

            default:
                {
                    s << "Unknown Item" << endl;
                    break;
                }
            }
        }
        s << "=============End============" << endl;
    }
    return s;
}

/*BagSlot Backpack::operator[](int index)
{
    return (*container)[index];
}*/

BagSlot Backpack::getItem(int index)
{
    auto item = (*container)[index];
}










