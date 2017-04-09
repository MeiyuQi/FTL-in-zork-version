#ifndef TIMENOW_H
#define TIMENOW_H
#include<iostream>
using namespace std;
#include <time.h>

class Clock{
    int s;
public:
    Clock(int s);
    ~Clock();
    void tick();
   // void show();
    bool run();
};

#endif // TIMENOW_H
