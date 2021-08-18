#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
    cout<<"Enter no.of disks in the sequence : ";
    int n;
    cin>>n;
    int sequence[n];
    cout<<"Enter the sequence : ";
    for(int i=0;i<n;i++)
        cin>>sequence[i];
    int head;
    cout<<"Enter the head start : ";
    cin>>head;
    int sum=abs(head-sequence[0]);
    for(int i=1;i<n;i++)
        sum=sum+abs(sequence[i-1]-sequence[i]);
    cout<<"No.of cylinders = "<<sum<<"\n";
    cout<<"Seek sequence is : ";
    cout<<head<<" ";
    for(int i=0;i<n;i++)
        cout<<sequence[i]<<" ";
}