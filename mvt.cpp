#include<iostream>
using namespace std;
int main()
{
    cout<<"---Multiprogramming with variable number of tasks---\n";
    cout<<"Enter total memory space (Bytes) : ";
    int msize,i=1,v,memory=0,op=1,p[10];
    cin>>msize;
    int temp=msize;
    while(op==1)
    {
        cout<<"Enter memory size for process - "<<i<<" : ";
        cin>>v;
        if(v<=msize)
        {
            cout<<"Process - "<<i<<" is allocated\n";
            p[i]=v;
            msize-=v;
            memory+=v;
            cout<<"Select an option : 1. Continue \t 2. Stop : ";
            cin>>op;
            i+=1;
        }
        else
        {
            cout<<"Memory is full\n";
            op=2;
        }
    }
    if(op==2)
    {
        cout<<"Size of main memory is "<<temp<<"\n";
        cout<<"Process \tMemory-allocated \n";
        for(int j=1;j<i;j++)
            cout<<"  "<<j<<" \t\t "<<p[j]<<"\n";
        cout<<"Total memory allocated = "<<memory<<"\n";
        cout<<"External fragmentation = "<<temp-memory;
    }
}