//Arrival times of processes are considered
#include <iostream>
using namespace std;
int wt[10], tt[10];
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void sort(int n, int ar[], int pid[], int bt[])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (ar[j] > ar[j + 1])
            {
                swap(&ar[j], &ar[j + 1]);
                swap(&pid[j], &pid[j + 1]);
                swap(&bt[j], &bt[j + 1]);
            }
        }
    }
}
void SJF(int n, int ar[], int pid[], int bt[])
{
    wt[0] = 0;
    tt[0] = bt[0];
    int t = bt[0];
    int min = 9999, x, j;
    for (int i = 1; i < n; i++)
    {
        min = 9999;
        for (j = i; j < n; j++)
        {
            if (ar[j] <= t && min > bt[j])
            {
                min = bt[j];
                x = j;
            }
        }
        swap(&pid[i], &pid[x]);
        swap(&ar[i], &ar[x]);
        swap(&bt[i], &bt[x]);
        wt[i] = t - ar[i];
        tt[i] = wt[i] + bt[i];
        t += bt[i];
    }
}
int main()
{
    int n, avg_wt = 0, avg_tt = 0;
    cout << "Enter no.of processes : ";
    cin >> n;
    int pid[n], bt[n], ar[n];
    cout << "Enter the process id's : ";
    for (int i = 0; i < n; i++)
        cin >> pid[i];
    cout << "Enter the burst times\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Burst time of process " << pid[i] << " is : ";
        cin >> bt[i];
    }
    cout << "Enter the arrival times\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Arrival time of process " << pid[i] << " is : ";
        cin >> ar[i];
    }
    sort(n, ar, pid, bt);
    SJF(n, ar, pid, bt);
    cout << "\tAfter SJF\n";
    cout << "Process_ID\tBurst time\tArrival time\tWaiting time\tTurn around time\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\t" << pid[i] << "\t\t" << bt[i] << "\t\t" << ar[i] << "\t\t" << wt[i] << "\t\t" << tt[i] << "\n";
        avg_wt += wt[i];
        avg_tt += tt[i];
    }
    cout << "Average waiting time = " << (float)avg_wt / n << "\n";
    cout << "Average turn around time = " << (float)avg_tt / n << "\n";
}