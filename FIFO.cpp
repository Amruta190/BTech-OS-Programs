#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter number of pages : ";
    int n,f;
    cin>>n;
    int p[n];
    cout<<"Enter the pages : ";
    for(int i=0;i<n;i++)
        cin>>p[i];
    cout<<"Enter number of frames : ";
    cin>>f;
    int m[f][n],first[n],z=0;
    char pf[n];
    for(int i=0;i<n;i++)
        pf[i]='-';
    m[0][0]=p[0];
    for(int i=1;i<f;i++)
        m[i][0]=-1;
    pf[0]='F';
    first[z++]=p[0];
    for(int i=1;i<n;i++)
    {
        int flag=0;
        for(int j=0;j<f;j++)
            m[j][i]=m[j][i-1];
        for(int j=0;j<f;j++)
        {
            if(m[j][i]==p[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            for(int j=1;j<f;j++)
            {
                if(m[j][i]==-1)
                {
                    m[j][i]=p[i];
                    pf[i]='F';
                    first[z++]=p[i];
                    flag=2;
                    break;
                }
            }
        }
        if(flag==0)
        {
            int tmp=first[0];
            for(int j=1;j<z;j++)
                first[j-1]=first[j];
            z--;
            for(int j=0;j<f;j++)
            {
                if(m[j][i]==tmp)
                    m[j][i]=p[i];
            }
            first[z++]=p[i];
            pf[i]='F';
        }
    }
    cout<<"Pages    : ";
    for(int i=0;i<n;i++)
        cout<<p[i]<<" ";
    cout<<"\nFIFO     : ";
    for(int i=0;i<f;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(m[i][j]==-1)
                cout<<"- ";
            else
                cout<<m[i][j]<<" ";
        }
        cout<<"\n           ";
    }
    int sum=0;
    cout<<"\nPg fault : ";
    for(int i=0;i<n;i++)
    {
        cout<<pf[i]<<" ";
        if(pf[i]=='F')
            sum+=1;
    }
    cout<<"\nTotal page faults = "<<sum;
}