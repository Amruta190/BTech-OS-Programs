#include<iostream>
using namespace std;
void constant_bsize(int msize,int bsize, int n,int p[])
{
    if(msize<bsize)
        cout<<"Memory size is less than block size !!!\n";
    else
    {
        int n1=msize/bsize;
        cout<<"Number of blocks formed = "<<n1<<"\n";
        int inf=0,cnt=0;
        cout<<"Process \tAllocation \tInternal-Fragmentation\n";
        cout<<"---------------------------------------------------------------------\n";
        for(int i=0;i<n;i++)
        {
            if(cnt>=n1)
            {
                cout<<"Memory is full\n";
                break;
            }
            if(p[i]<=bsize)
            {
                cout<<"\t"<<i+1<<"\t Allocated \t"<<bsize-p[i]<<"\n";
                inf+=bsize-p[i];
                cnt+=1;
            }
            else if(p[i]>bsize)
            {
                cout<<"\t"<<i+1<<"\t Not Allocated \t---\n";
            }
        }
        cout<<"Total Internal fragmentation - "<<inf<<"\n";
        cout<<"Total External fragmentation - "<<msize-(n1*bsize);
    }
}
void variable_bsize(int msize,int n,int p[],int n1,int block_sizes[])
{
    int sum=0;
    for(int i=0;i<n1;i++)
        sum+=block_sizes[i];
    if(msize<sum)
        cout<<"Memory size is less than sum of block sizes !!!\n";
    else
    {
        cout<<"Process \tAllocation \tInternal-Fragmentation\n";
        cout<<"---------------------------------------------------------------------\n";
        int cnt=0,inf=0,x;
        for(int i=0;i<n;i++)
        {
            int min=9999;
            if(cnt>=n1)
            {
                cout<<"Memory is full\n";
                break;
            }
            for(int j=0;j<n1;j++)
            {
                if(p[i]<=block_sizes[j] && min>block_sizes[j]-p[i])
                {
                    min=block_sizes[j]-p[i];
                    x=j;
                }
            }
            if(min==9999)
                cout<<"\t"<<i+1<<"\t Not Allocated \t---\n";
            else
            {
                cout<<"\t"<<i+1<<"\t Allocated \t"<<block_sizes[x]-p[i]<<"\n";
                inf+=block_sizes[x]-p[i];
                cnt+=1;
                block_sizes[x]=0;
            }
        }
        cout<<"Total Internal fragmentation - "<<inf<<"\n";
        cout<<"Total External fragmentation - "<<msize-sum;
    }
}
int main()
{
    cout<<"---Multiprogramming with fixed number of tasks---\n";
    int msize,n,op;
    cout<<"Enter total memory space (Bytes) : ";
    cin>>msize;
    cout<<"Enter number of processes : ";
    cin>>n;
    int p[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Size of process - "<<i+1<<" : ";
        cin>>p[i];
    }
    cout<<"Select an option : \n1. Fixed block sizes\t2. Variable block sizes\n";
    cin>>op;
    if(op==1)
    {
        int bsize;
        cout<<"Enter block size : ";
        cin>>bsize;
        constant_bsize(msize,bsize,n,p);
    }
    else if(op==2)
    {
        cout<<"Enter number of blocks : ";
        int n1;
        cin>>n1;
        int block_sizes[n1];
        for(int i=0;i<n1;i++)
        {
            cout<<"Size of block - "<<i+1<<" : ";
            cin>>block_sizes[i];
        }
        variable_bsize(msize,n,p,n1,block_sizes);
    }
}