#ifndef SHIP_H
#define SHIP_H
#include <Character.h>
#include <string>
#include <iostream>
using namespace std;

class Ship : public Character{
    string description;
    string weapon;

   // int power;
public:
    bool get_key = false;
    Ship();
    ~Ship();
    Ship(string description);
    string get_des();
    string get_ship_name();
    void attack(Ship *a, int val);
    string check_weapon();
    void change_weapon(string weapon);
    bool is_kill(int power);
    template <class T> T comp(T a, T b){
        return (a<b)?a:b;
    }
    string test_temp(string a,string b);
    int test_temp(int a, int b);
   Ship operator+(const Ship &c);
};


#endif // SHIP_H
