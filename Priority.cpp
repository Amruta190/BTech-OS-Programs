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
void sort(int n,int pr[],int pid[],int bt[])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for (j=0;j<n-i-1;j++)
        {
            if (pr[j] > pr[j+1]) 
            {
                swap(&pr[j],&pr[j+1]);
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
int main()
{
    int n,avg_wt=0,avg_tt=0;
    cout<<"Enter no.of processes : ";
    cin>>n;
    int pid[n],bt[n],pr[n];
    cout<<"Enter the process id's : ";
    for(int i=0;i<n;i++)
        cin>>pid[i];
    cout<<"Enter the burst times\n";
    for(int i=0;i<n;i++)
    {
        cout<<"Burst time of process "<<pid[i]<<" is : ";
        cin>>bt[i];
    }
    cout<<"Enter the priorities\n";
    for(int i=0;i<n;i++)
    {
        cout<<"Priority of process "<<pid[i]<<" is : ";
        cin>>pr[i];
    }
    sort(n,pr,pid,bt);
    FCFS(n,pid,bt);
    cout<<"\tAfter Priority scheduling \n";
    cout<<"Process_ID\tBurst time\tPriority\tWaiting time\tTurn around time\n";
    for(int i=0;i<n;i++)
    {
        cout<<"\t"<<pid[i]<<"\t\t"<<bt[i]<<"\t\t"<<pr[i]<<"\t\t"<<wt[i]<<"\t\t"<<tt[i]<<"\n";
        avg_wt+=wt[i];
        avg_tt+=tt[i];
    }
    cout<<"Average waiting time = "<<(float)avg_wt/n<<"\n";
    cout<<"Average turn around time = "<<(float)avg_tt/n<<"\n";
}