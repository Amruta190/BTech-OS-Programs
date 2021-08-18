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
    int n,size;
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
    cout<<"Enter the disk size : ";
    cin>>size;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(sequence[i]>sequence[j])
                sort(&sequence[i],&sequence[j]);
        }
    }
    n=n+1;
    sequence[n-1]=size;
    int ind;
    cout<<"Seek sequence is : ";
    cout<<head<<" ";
    for(int i=0;i<n;i++)
    {   
        if(head==sequence[i])
            ind=i;
    }
    for(int i=ind+1;i<n;i++)
        cout<<sequence[i]<<" ";
    if(head!=0)
        cout<<"0 ";
    for(int i=0;i<ind;i++)
        cout<<sequence[i]<<" ";
    if(head!=0 && ind!=0)
        cout<<"\nNo.of cylinders = "<<(size-head)+size+sequence[ind-1]<<"\n";
    else if(head==0)
        cout<<"\nNo.of cylinders = "<<sequence[n-2]<<"\n";
    else
        cout<<"\nNo.of cylinders = "<<sequence[n-2]-head<<"\n";
}