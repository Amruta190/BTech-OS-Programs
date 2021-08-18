#include "windows.h"
#include <iostream>
using namespace std;
int wait(int s)
{
    while (s <= 0)
        ;
    s--;
    // Sleep(2);
    return s;
}
int signal(int s)
{
    s++;
    return s;
}
int Philosopher(int chopstick[], int i)
{
    // do{
        chopstick[i]=wait(chopstick[i]);
        chopstick[i]=wait(chopstick[(i+1)%5]);
        Sleep(2);
        //eat
        chopstick[i]=signal(chopstick[i]);
        chopstick[i]=signal(chopstick[(i+1)%5]);
        //think
    // }while(true);
}
int main()
{
    cout<<"Enter number of philosophers : ";
    int n;
    cin>>n;
    int chopstick[n];
    for(int i=0;i<n;i++)
        chopstick[i]=0;
    for(int i=0;i<n;i++)
    {
        Philosopher(chopstick,i);
        // for(int i=0;i<n;i++)
        cout<<chopstick[i]<<" ";
    }
}