#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <string>
#include <vector>
#include <iostream>

class ItemBase;
class Player
{
private:
    std::string PlayerName;
    int HP;
    int HPMax;
    int MP;
    int MPMax;
    int Level;
    int LevelMax;
    long Exp;
    long ExpNext;

    int (*HPFunc)(int);
    int (*MPFunc)(int);
    long (*ExpNextFunc)(int);

public:
    Player(std::string PlayerName,
           int defHP,
           int defMP,
           int lvlmax,
           int (*HPF)(int),
           int (*MPF)(int),
           long (*NEF)(int));
    ~Player();

    std::string getPlayerName();
    int getHP();
    int getHPMax();
    int getMP();
    int getMPMax();
    long getExp();
    long getNextExp();

    void GainExp(int exp);
    void LevelUp();

    void addHP(int val);
    void setHP(int val);
    void addMP(int val);
    void setMP(int val);

    void ShowBag();
    ItemBase* getItemByID(int id);


    friend std::ostream& operator<<(std::ostream& s, Player* obj);

};

#endif // __PLAYER_H__
