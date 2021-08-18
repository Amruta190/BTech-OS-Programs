#include<iostream>
#include<cstdlib>
using namespace std;
void sort(int *a,int *b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
int main()
{
    cout<<"Enter no.of disks in the sequence : ";
    int n;
    cin>>n;
    n=n+1;
    int sequence[n];
    cout<<"Enter the sequence : ";
    for(int i=1;i<n;i++)
        cin>>sequence[i];
    int head;
    cout<<"Enter the head start : ";
    cin>>head;
    sequence[0]=head;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(sequence[i]>sequence[j])
                sort(&sequence[i],&sequence[j]);
        }
    }
    int ind;
    cout<<"No.of cylinders = "<<head+sequence[n-1]<<"\n";
    cout<<"Seek sequence is : ";
    cout<<head<<" ";
    for(int i=0;i<n;i++)
    {   
        if(head==sequence[i])
            ind=i;
    }
    for(int i=ind-1;i>=0;i--)
        cout<<sequence[i]<<" ";
    if(head!=0)
        cout<<"0 ";
    for(int i=ind+1;i<n;i++)
        cout<<sequence[i]<<" ";
}