//All processes arraived at time t=0
#include<iostream>
using namespace std;
int wt[10],tt[10];
void Round_robin(int n,int pid[],int bt[],int quant)
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
            if(rem_bt[i]>quant)
            {
                t+=quant;
                rem_bt[i]-=quant;
            }
            else if(rem_bt[i]!=0)
            {
                t+=rem_bt[i];
                wt[i]=t-bt[i];
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
    int pid[n],bt[n];
    cout<<"Enter the process id's : ";
    for(int i=0;i<n;i++)
        cin>>pid[i];
    cout<<"Enter the burst times\n";
    for(int i=0;i<n;i++)
    {
        cout<<"Burst time of process "<<pid[i]<<" is : ";
        cin>>bt[i];
    }
    cout<<"Enter quantum size : ";
    cin>>quant;
    Round_robin(n,pid,bt,quant);
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