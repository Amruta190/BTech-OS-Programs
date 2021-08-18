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
    int m[f][n];
    char pf[n];
    for(int i=0;i<n;i++)
        pf[i]='-';
    m[0][0]=p[0];
    for(int i=1;i<f;i++)
        m[i][0]=-1;
    pf[0]='F';
    int cnts[f];
    for(int j=1;j<f;j++)
        cnts[j]=0;
    cnts[0]=1;
    for(int i=1;i<n;i++)
    {
        int flag=0;
        for(int j=0;j<f;j++)
            m[j][i]=m[j][i-1];
        for(int j=0;j<f;j++)
        {
            if(m[j][i]==p[i])
            {
                cnts[j]+=1;
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
                    cnts[j]+=1;
                    pf[i]='F';
                    flag=2;
                    break;
                }
            }
        }
        if(flag==0)
        {
            pf[i]='F';
            int min=99,x;
            for(int j=0;j<f;j++)
            {
                if(min>cnts[j])
                {
                    min=cnts[j];
                    x=j;
                }
            }
            m[x][i]=p[i];
            cnts[x]=1;
        }
    }
    cout<<"Pages    : ";
    for(int i=0;i<n;i++)
        cout<<p[i]<<" ";
    cout<<"\nLFU      : ";
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