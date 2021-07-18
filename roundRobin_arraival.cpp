#include<iostream>
using namespace std;
int wt[10],tt[10];
void swap(int *a,int *b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
void sort(int n,int ar[],int pid[],int bt[])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for (j=0;j<n-i-1;j++)
        {
            if (ar[j] > ar[j+1]) 
            {
                swap(&ar[j],&ar[j+1]);
                swap(&pid[j],&pid[j+1]);
                swap(&bt[j],&bt[j+1]);
            }
        }
    }
}
void Round_robin(int n,int pid[],int bt[],int ar[],int quant)
{
    int rem_bt[n],sum=0;
    for(int i=0;i<n;i++)
    {
        rem_bt[i]=bt[i];
        sum+=bt[i];
    }
    int t=0;
    while(t<sum)
    {
        int i=0;
        for(i=0;i<n;i++)
        {
            if(rem_bt[i]>quant && ar[i]<=t)
            {
                t+=quant;
                rem_bt[i]-=quant;
            }
            else if(rem_bt[i]!=0 && ar[i]<=t)
            {
                t+=rem_bt[i];
                wt[i]=t-bt[i]-ar[i];
                rem_bt[i]=0;
            }
        }
    }
    for(int i=0;i<n;i++)
        tt[i]=wt[i]+bt[i];
}
int main()
{
    int n,avg_wt=0,avg_tt=0,quant;
    cout<<"Enter no.of processes : ";
    cin>>n;
    int pid[n],bt[n],ar[n];
    cout<<"Enter the process id's : ";
    for(int i=0;i<n;i++)
        cin>>pid[i];
    cout<<"Enter the burst times\n";
    for(int i=0;i<n;i++)
    {
        cout<<"Burst time of process "<<pid[i]<<" is : ";
        cin>>bt[i];
    }
    cout<<"Enter the arraival times\n";
    for(int i=0;i<n;i++)
    {
        cout<<"Arraival time of process "<<pid[i]<<" is : ";
        cin>>ar[i];
    }
    cout<<"Enter quantum size : ";
    cin>>quant;
    sort(n,ar,pid,bt);
    Round_robin(n,pid,bt,ar,quant);
    cout<<"\tAfter Round Robin scheduling \n";
    cout<<"Process_ID\tBurst time\tWaiting time\tTurn around time\n";
    for(int i=0;i<n;i++)
    {
        cout<<"\t"<<pid[i]<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tt[i]<<"\n";
        avg_wt+=wt[i];
        avg_tt+=tt[i];
    }
    cout<<"Average waiting time = "<<(float)avg_wt/n<<"\n";
    cout<<"Average turn around time = "<<(float)avg_tt/n<<"\n";
}