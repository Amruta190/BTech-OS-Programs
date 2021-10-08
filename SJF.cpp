#include<iostream>
using namespace std;
int wt[10],tt[10];
void sort(int n,int bt[],int pid[])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(bt[j]>bt[j+1])
            {
                swap(bt[j],bt[j+1]);
                swap(pid[j],pid[j+1]);
            }
        }
    }
}
void FCFS(int n,int bt[],int pid[])
{
    int i;
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+bt[i-1];
        tt[i-1]=wt[i-1]+bt[i-1];
    }
    tt[i-1]=wt[i-1]+bt[i-1];
}
int main()
{
    int n;
    cout<<"Enter no.of processes : ";
    cin>>n;
    cout<<"Enter process id's : ";
    int pid[n];
    for(int i=0;i<n;i++)
        cin>>pid[i];
    cout<<"Enter burst times : ";
    int bt[n];
    for(int i=0;i<n;i++)
        cin>>bt[i];
    sort(n,bt,pid);
    FCFS(n,bt,pid);
    int avg_wt=0,avg_tt=0;
    cout<<"Process id\tburst time\twaiting time\tturn around time\n";
    for(int i=0;i<n;i++)
    {
        cout<<"\t"<<pid[i]<<"\t"<<bt[i]<<"\t"<<wt[i]<<"\t"<<tt[i]<<"\n";
        avg_wt+=wt[i];
        avg_tt+=tt[i];
    }
    cout<<"Average waiting time = "<<(float)avg_wt/n;
    cout<<"\nAverage turn around time = "<<(float)avg_tt/n;
}