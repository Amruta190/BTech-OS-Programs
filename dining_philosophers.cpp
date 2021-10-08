#include <iostream>
using namespace std;
int n,visited[100],chopstick[100];
int wait(int s)
{
    while (s <= 0)
        ;
    s--;
    return s;
}
int signal(int s)
{
    s++;
    return s;
}
bool areAllVisited()
{
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=visited[i];
    if(sum==n)
        return true;
    else
        return false;
}
int Philosopher()
{
    for(int i=0;i<n;i++)
        visited[i]=0;
    while(!areAllVisited())
    {
        for(int i=0;i<n;i++)
        {
            if(visited[(i+1)%n]==0)
            {
                if(chopstick[i]==1 && chopstick[(i+1)%n]==1)
                {
                    chopstick[i]=wait(chopstick[i]);
                    chopstick[(i+1)%n]=wait(chopstick[(i+1)%n]);
                    cout<<"Philosopher "<<(i+1)%n<<" is eating\n";
                    visited[(i+1)%n]=1;
                }
                else
                    cout<<"Philosopher "<<(i+1)%n<<" is thinking\n";
            }
            else
                cout<<"Philosopher "<<(i+1)%n<<" is thinking\n";
        }
        cout<<"\n-----------------------------------------------------------\n";
        for(int i=0;i<n;i++)
        {
            if((chopstick[i]==0 && chopstick[(i+1)%n]==0))
            {
                chopstick[i]=signal(chopstick[i]);
                chopstick[(i+1)%n]=signal(chopstick[(i+1)%n]);
            }
        }
    }
}
int main()
{
    cout<<"Enter number of philosophers : ";
    cin>>n;
    for(int i=0;i<n;i++)
        chopstick[i]=1;
    Philosopher();
}