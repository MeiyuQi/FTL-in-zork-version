#ifndef CHARACTER_H_
#define CHARACTER_H_
#include <string>
#include "item.h"
#include <vector>

using namespace std;
using std::vector;


class Character {
private:
    int power=10;
    string description;
    vector < Item > itemsInCharacter;
  //  vector < Item > itemsInCharacter;
public:
    void addItems(string Item);
    void setPower(string power);
    void setPower(int power,string set);
    int getPower();
    Character();
    ~Character();
    Character(string description);

    virtual string get_des(){

        return "virtual";
    }

};

#endif /*CHARACTER_H_*/
