#include<iostream>
using namespace std;
void first_fit(int n,int blocks[],int p,int process[])
{
    cout<<"\n---------First fit---------\n";
    cout<<"Process size\tBlock No\n";
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(process[i]<=blocks[j])
            {
                cout<<"\t"<<process[i]<<"\t"<<j+1<<"\n";
                blocks[j]-=process[i];
                break;
            }
            if(j==n-1)
                cout<<"\t"<<process[i]<<"\t"<<"No allocation place\n";
        }
    }
}
void best_fit(int n,int blocks[],int p,int process[])
{
    cout<<"\n---------Best fit---------\n";
    cout<<"Process size\tBlock No\n";
    for(int i=0;i<p;i++)
    {
        int min=9999,x=-1;
        for(int j=0;j<n;j++)
        {
            if(process[i]<=blocks[j] && min>=blocks[j]-process[i])
            {
                min=blocks[j]-process[i];
                x=j;
            }
        }
        if(x==-1)
            cout<<"\t"<<process[i]<<"\t"<<"No allocation place\n";
        else
        {
            cout<<"\t"<<process[i]<<"\t"<<x+1<<"\n";
            blocks[x]-=process[i];
        }
    }
}
void worst_fit(int n,int blocks[],int p,int process[])
{
    cout<<"\n---------Worst fit---------\n";
    cout<<"Process size\tBlock No\n";
    for(int i=0;i<p;i++)
    {
        int max=0,x=-1;
        for(int j=0;j<n;j++)
        {
            if(process[i]<=blocks[j] && max<=blocks[j]-process[i])
            {
                max=blocks[j]-process[i];
                x=j;
            }
        }
        if(x==-1)
            cout<<"\t"<<process[i]<<"\t"<<"No allocation place\n";
        else
        {
            cout<<"\t"<<process[i]<<"\t"<<x+1<<"\n";
            blocks[x]-=process[i];
        }
    }
}
int main()
{
    cout<<"Enter the no.of blocks : ";
    int n,p;
    cin>>n;
    int blocks[n];
    cout<<"Enter the block sizes : \n";
    for(int i=0;i<n;i++)
        cin>>blocks[i];
    cout<<"Enter the no.of process : ";
    cin>>p;
    int process[p];
    cout<<"Enter the processes sizes : \n";
    for(int i=0;i<p;i++)
        cin>>process[i];
    int block_sizes[n],process_sizes[p];
    for(int i=0;i<n;i++)
        block_sizes[i]=blocks[i];
    for(int i=0;i<p;i++)
        process_sizes[i]=process[i];
    first_fit(n,blocks,p,process);
    for(int k=0;k<n;k++)
        blocks[k]=block_sizes[k];
    best_fit(n,blocks,p,process);
    for(int k=0;k<n;k++)
        blocks[k]=block_sizes[k];
    worst_fit(n,blocks,p,process);
}