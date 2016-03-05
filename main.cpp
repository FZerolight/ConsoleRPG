#include <iostream>
#include <windows.h>
#include "Item.h"
#include "Player.h"

using namespace std;

int PHPNext(int lvl)
{
    return 150+lvl*100;
}

int PMPNext(int lvl)
{
    return 250+lvl*175;
}

long PExpNext(int lvl)
{
    return 200+lvl*75;
}

int main()
{
    //cout <<"Welcome to the Game World!"<<endl;
    Sleep(2000);
    Player* pMainChar = new Player("Mikoto Misaka",
                                100,
                                100,
                                255,
                                PHPNext,
                                PMPNext,
                                PExpNext);
    HealthPotion* pRec = new HealthPotion(100);
    Sleep(1000);
    cout << pRec << endl;
    Sleep(2000);
    pMainChar->GainExp(2000);
    Sleep(1000);
    pMainChar->addHP(-200);
    Sleep(2000);
    pRec->Use(pMainChar);

    return 0;
}
