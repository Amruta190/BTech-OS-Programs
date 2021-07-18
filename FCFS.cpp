//All processes arraived at time t=0
#include<iostream>
using namespace std;
int wt[10],tt[10];
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
int main()
{
    int n,avg_wt=0,avg_tt=0;
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
    FCFS(n,pid,bt);
    cout<<"\tAfter FCFS\n";
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