#ifndef __ITEM_H__
#define __ITEM_H__

#include <string>
#include <iostream>
#include "Player.h"

class ItemBase
{
private:
    int ItemID;
    std::string ItemName;

public:
    int MaxCarried;

    ItemBase(int ID, std::string Name, int MCarried);
    ~ItemBase();

    std::string getItemName();
    int getItemID();
};

class HealthPotion : public ItemBase
{
private:
    int RecValue;

public:
    HealthPotion(int RecoveryValue);
    ~HealthPotion();
    void Use(Player* player);
    void Destroy();

    friend std::ostream& operator<<(std::ostream& s, HealthPotion* obj);

};

class Abrakadabra : public ItemBase
{
private:
    int duration;

public:
    Abrakadabra();
    ~Abrakadabra();

    void update();
    void Use(Player* player);
    void Destroy();
};
#endif // _ITEM_H__
