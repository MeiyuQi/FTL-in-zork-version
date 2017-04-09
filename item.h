#ifndef ITEM_H_
#define ITEM_H_
#include <map>
#include <string>
#include <iostream>

using namespace std;

class Item {
private:
    string description;
    string longDescription;
    bool weaponCheck;

public:
    Item();
    ~Item();
   // Item (Ship enemy,string description);
    Item (string description);
    string getShortDescription();
    string getLongDescription();
    int getWeaponCheck();
    void setWeaponCheck(int weaponCheck);
};

#endif /*ITEM_H_*/
