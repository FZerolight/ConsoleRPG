#include "Item.h"
#include "Player.h"
#include "Common.h"
#include <iostream>

using namespace std;

ItemBase::ItemBase(int ID, string Name, int MC)
{
    this->ItemID = ID;
    this->ItemName = Name;
    this->MaxCarried = MC;
}

//class ItemBase
ItemBase::~ItemBase()
{
    //
}

int ItemBase::getItemID()
{
    return this->ItemID;
}

string ItemBase::getItemName()
{
    return this->ItemName;
}

//class HealthPotion
HealthPotion::HealthPotion(int RecoveryValue):ItemBase(Item_HP, "HealthPotion", 99)
{
    this->RecValue = RecoveryValue;
}

HealthPotion::~HealthPotion()
{
    //
}

void HealthPotion::Use(Player* player)
{
    cout << player->getPlayerName() << " has used the HealthPotion" << endl;
    player->addHP(this->RecValue);
    this->Destroy();
}

void HealthPotion::Destroy()
{
    cout << "The HealthPotion Vanished"<<endl;
    this->~HealthPotion();
}

ostream& operator<<(ostream & s, HealthPotion* obj)
{
    s << "ItemID:" << obj->getItemID() << endl;
    s << "ItemName:" << obj->getItemName() << endl;
    return s;
}
