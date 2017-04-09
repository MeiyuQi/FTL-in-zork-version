#include "timenow.h"
Clock::Clock(int s){
    this->s = s;
}
void Clock::tick()
{
    time_t t=time(NULL);
    while(time(NULL)==t);
    if(--s<0){
        s=59;
    }
}
//void Clock::show()
//{
//    cout<<'\r';
//    if(s<10)cout<<0;
//    cout<<s<<flush;
//}
bool Clock::run()
{
    while(s!=0){
        tick();
        //show();
    }
//    cout<<endl<<"Time out!"<<endl;
//    cout<<'\a';
    return true;
}
Clock::~Clock(){
    cout<<"bye clock"<<endl;
}
//int main()
//{
//    Clock c;
//    c.run();
//}
