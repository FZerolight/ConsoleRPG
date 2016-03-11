#include "Player.h"
#include <iostream>
#include "Backpack.h"
#include "Common.h"

using namespace std;

Player::Player(string PN,
               int dHP,
               int dMP,
               int lvlmax,
               int (*HPF)(int),
               int (*MPF)(int),
               long (*NEF)(int))
{
    this->HP = dHP;
    this->HPMax = dHP;
    this->MP = dMP;
    this->MPMax = dMP;
    this->PlayerName = PN;
    this->Level = 1;
    this->LevelMax = lvlmax;
    this->Exp = 0;
    this->HPFunc = HPF;
    this->MPFunc = MPF;
    this->ExpNextFunc = NEF;
    this->ExpNext = this->ExpNextFunc(this->Level);
    PlayerBag = new Backpack(99);

    Attributes[ATK] = 20;
    Attributes[DEF] = 10;
    Attributes[STR] = 10;
    Attributes[INT] = 10;
    Attributes[AGL] = 10;

    cout << "Welcome, " << this->PlayerName << "!" << endl;
    cout << this;
}

Player::~Player()
{
    //
}

string Player::getPlayerName()
{
    return PlayerName;
}

int Player::getHP()
{
    return HP;
}

int Player::getHPMax()
{
    return HPMax;
}

int Player::getMP()
{
    return MP;
}

int Player::getMPMax()
{
    return MPMax;
}

long Player::getExp()
{
    return Exp;
}

long Player::getNextExp()
{
    return ExpNext;
}

void Player::GainExp(int exp)
{
    Exp += exp;
    cout << PlayerName << " has got "<< exp << " Exp!" << endl;
    while (Exp >= ExpNext)
    {
        Exp -= ExpNext;
        LevelUp();
    }
}

void Player::LevelUp()
{
    if (Level > LevelMax)
    {
        cout << "You cannot get more Exp!" << endl;
    }
    else
    {
        Level++;
        ExpNext = ExpNextFunc(Level);
        HPMax = HPFunc(Level);
        HP = HPMax;
        MPMax = MPFunc(Level);
        MP = MPMax;
        cout << "Level Up!" << endl;
        cout << PlayerName << " has reached Level " << Level << endl;
        cout << this;
    }
}

void Player::addHP(int val)
{
    HP += val;
    if (HP > HPMax)
    {
        HP = HPMax;
    }
    if (val > 0)
    {
        cout << PlayerName << "'s HP has just recovered by "<< val <<endl;
    }
    else
    {
        cout << PlayerName << "'s HP just been decreased by "<< val <<endl;
    }
}

void Player::setHP(int val)
{
    HP = val;
    if (HP > HPMax)
    {
        HP = HPMax;
    }
    cout << PlayerName << "'s HP has been set to " << HP << endl;
}

void Player::addMP(int val)
{
    MP += val;
    if (MP > MPMax)
    {
        MP = MPMax;
    }
    if (val > 0)
    {
        cout << PlayerName << "'s MP has just recovered by "<< val <<endl;
    }
    else
    {
        cout << PlayerName << "'s MP just been decreased by "<< val <<endl;
    }
}

void Player::setMP(int val)
{
    MP = val;
    if (MP > MPMax)
    {
        MP = MPMax;
    }
    cout << PlayerName << "'s MP has been set to " << HP << endl;
}

void Player::addItem(ItemBase* item, int num)
{
    BagSlot bs;
    bs.Item = item;
    bs.Num = num;
    if (PlayerBag->add(bs))
    {
        cout << "Player " << PlayerName << "has get " << num << " " << item->getItemName();
        if (num > 1)
        {
            cout << "s";
        }
        cout << endl;
    }
    else
    {
        cout << PlayerBag->getLog();
    }
}

void Player::showBag()
{
    cout << PlayerBag << endl;
}

ostream& operator<<(std::ostream& s, Player* obj)
{
    s << "Your status now:"<<endl;
    s << "HP: " << obj->HP << " / " << obj->HPMax << endl;
    s << "MP: " << obj->MP << " / " << obj->MPMax << endl;
    s << "Exp:" << obj->Exp << " / " << obj->ExpNext << endl;
    return s;
}
