#include<iostream>
using namespace std;
int chopstick[5]={1,1,1,1,1};
int wait(int s)
{
    while (s <= 0)
        ;
    s--;
    return s;
}
int signal(int s)
{
    s++;
    return s;
}
int Philosopher(int i)
{
    // do{
        chopstick[i]=wait(chopstick[i]);
        chopstick[i]=wait(chopstick[(i+1)%5]);
        //eat
        chopstick[i]=signal(chopstick[i]);
        chopstick[i]=signal(chopstick[(i+1)%5]);
        //think
    // }while(true);
}
int main()
{
    Philosopher(1);
    for(int i=0;i<5;i++)
        cout<<chopstick[i]<<" ";
}