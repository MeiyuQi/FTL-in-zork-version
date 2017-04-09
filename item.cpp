#include "item.h"

//Item::Item (Ship enemy, string description) {
//    enemy = new Ship(description);
//    description = description;
//}


Item::Item(){

}
Item::~Item(){
    cout<<"bye item"<<endl;
}

Item::Item(string inDescription) {
    description = inDescription;
}


/**void Item::setWeaponCheck(int isWeapon)
{
    if(isWeapon > 0 || isWeapon < 0)
        cout << "Item not a weapon" ;
    else
        cout << "Item is a weapon" ;
}*/

string Item::getShortDescription()
{
    return description;
}

string Item::getLongDescription()
{
    return " item(s), " + description + ".\n";
}

