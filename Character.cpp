#include "Character.h"

Character::Character(){

}
Character::~Character(){
    cout<<"bye character"<<endl;
}
Character::Character(string description) {
    this->description = description;
}

void Character::setPower(string power){
    if(power.compare("power +10")==0){
            this->power+=10;
    }
    else if(power.compare("power +5")==0){
        this->power+=5;
    }
}
void Character::setPower(int power,string set){
    if(set=="-")
    this->power-=power;
    else if(set=="+")
        this->power=10;
}
int Character::getPower(){
    return this->power;
}
