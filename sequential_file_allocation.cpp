#include<iostream>
using namespace std;
int main()
{
    int i=0,flag=1,arr[100][2],z[100];
    for(int j=0;j<101;j++)
        z[j]=0;
    string names[100];
    while(flag)
    {
        char ch;
        int len;
        cout<<"Enter file name : ";
        cin>>names[i];
        cout<<"Enter start block of file : ";
        cin>>arr[i][0];
        cout<<"Enter length of file : ";
        cin>>arr[i][1];
        int f=0;
        for(int j=arr[i][0];j<arr[i][0]+arr[i][1];j++)
        {
            if(z[j]==0)
                z[j]=1;
            else
            {
                f=1;
                i--;
                break;
            }
        }
        if(f==1)
            cout<<"File not allocated";
        else
        {
            cout<<"File allocated\n";
            cout<<"Blocks filled are : ";
            for(int k=arr[i][0];k<arr[i][0]+arr[i][1];k++)
                cout<<k<<" ";
        }
        cout<<"\nEnter another file ? Y:N - ";
        cin>>ch;
        if(ch=='Y')
            flag=1;
        else if(ch=='N')
        {
            flag=0;
            cout<<"\n-----Allocated files are-----\nFile\tStart\tLength\n";
            for(int p=0;p<=i;p++)
                cout<<names[p]<<"\t"<<arr[p][0]<<"\t"<<arr[p][1]<<"\n";
        }
        i++;
    }
}