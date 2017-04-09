#include "ship.h"

Ship::Ship(){

}
Ship::~Ship(){
    cout<<"bye ship"<<endl;
}
Ship Ship::operator +(const Ship &c){
   Ship b;
    b.description="operator"+c.description;
    return b;
}
Ship::Ship(string description){
    this->description = description;
    if(description == "enemyb")
    {
    this->weapon = "Missiles";
    }
    else if(description =="enemyd")
    {
        this->weapon = "Lasers";
    }
    else if(description =="enemyf")
    {
        this->weapon = "Lasers";
    }
    else
     {
        this->weapon = "Missiles";
    }

}

string Ship::get_des(){
    if(this->weapon.compare("Missiles")==0)
        return this->description + "\nweapon： " + this->weapon+"(Hurt enemy 3 power points each time)\n";
    else
         return this->description + "\nweapon： " + this->weapon+"(Hurt enemy 5 power points each time)\n";

}
int Ship::test_temp(int a,int b){
    int p = comp(a,b);
    return p;
}
string Ship::test_temp(string a, string b){
    string c = comp(a,b);
    return c;
}
string Ship::get_ship_name(){
    return this->description;
}

void Ship::attack(Ship *a, int val){
    a->setPower(val,"-");

}
bool Ship::is_kill(int power){
    if(power<0)
        return true;
    return false;
}
void Ship::change_weapon(string weapon){
       this->weapon = weapon;
}
string Ship::check_weapon(){
    return this->weapon;
}
