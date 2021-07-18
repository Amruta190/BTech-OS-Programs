//All processes arraived at time t=0
#include<iostream>
using namespace std;
int wt[10],tt[10];
void swap(int *a,int *b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
void sort(int n,int q[],int pid[],int bt[])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for (j=0;j<n-i-1;j++)
        {
            if (q[j] > q[j+1]) 
            {
                swap(&q[j],&q[j+1]);
                swap(&pid[j],&pid[j+1]);
                swap(&bt[j],&bt[j+1]);
            }
        }
    }
}
void FCFS(int n,int pid[],int bt[])
{
    int i;
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=bt[i-1]+wt[i-1];
        tt[i-1]=wt[i-1]+bt[i-1];
    }
    tt[i-1]=wt[i-1]+bt[i-1];
}
void Round_robin(int k,int n,int pid[],int bt[],int quant)
{
    int rem_bt[n],sum=0;
    for(int i=k;i<n;i++)
    {
        rem_bt[i]=bt[i];
        sum+=bt[i];
    }
    int t=0;
    while(t<sum)
    {
        int i=k;
        for(i=k;i<n;i++)
        {
            if(rem_bt[i]>quant)
            {
                t+=quant;
                rem_bt[i]-=quant;
            }
            else if(rem_bt[i]!=0)
            {
                t+=rem_bt[i];
                wt[i]=t-bt[i]+tt[k-1];
                rem_bt[i]=0;
            }
        }
    }
    for(int i=k;i<n;i++)
        tt[i]=wt[i]+bt[i];
}
int main()
{
    int n,avg_wt=0,avg_tt=0,quant;
    cout<<"Enter no.of processes : ";
    cin>>n;
    int pid[n],bt[n],q[n];
    cout<<"Enter the process id's : ";
    for(int i=0;i<n;i++)
        cin>>pid[i];
    cout<<"Enter the burst times\n";
    for(int i=0;i<n;i++)
    {
        cout<<"Burst time of process "<<pid[i]<<" is : ";
        cin>>bt[i];
    }
    cout<<"Queue-1 : FCFS\nQueue-2 : Round-robin\n";
    cout<<"Enter the queue number\n";
    for(int i=0;i<n;i++)
    {
        cout<<"Queue number 1 or 2 of process : "<<pid[i];
        cin>>q[i];
    }
    cout<<"Enter quantum size : ";
    cin>>quant;
    sort(n,q,pid,bt);
    int i=0;
    while(q[i]==1)
        i++;
    FCFS(i,pid,bt);
    Round_robin(i,n,pid,bt,quant);
    cout<<"\tAfter Multi-level queue\n";
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