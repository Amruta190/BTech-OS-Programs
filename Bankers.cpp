#include<iostream>
using namespace std;
int all[100][100],need[100][100],Available[100];
void Safety(int n,int r)
{
    int work[r];
    bool finish[n];
    for(int i=0;i<n;i++)
        finish[i]=false;
    for(int i=0;i<r;i++)
        work[i]=Available[i];
    cout<<"\n";
    int final=n,k=0,p=0,seq[n],flag1=0;
    for(int i=0;i<n;i=(i+1)%n)
    {
        int flag=0;
        if(i==0)
            k=0;
        if(finish[i]==false)
        {
            for(int j=0;j<r;j++)
            {
                if(need[i][j]>work[j])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                for(int j=0;j<r;j++)
                {
                    work[j]=work[j]+all[i][j];
                }
                finish[i]=true;
                k+=1;
                final=final-1;
                // cout<<"P"<<i<<" ";
                seq[p++]=i;
            }
        }
        else if(final==0)
            break;
        if((i+1)==n && k==0)
        {
            cout<<"-----Unsafe!-----";
            flag1=1;
            break;
        }
    }
    if(flag1==0)
    {
        cout<<"Safe sequence : ";
        for(int i=0;i<p;i++)
            cout<<"P"<<seq[i]<<" ";
    }
}
int main()
{
    int r,n;
    cout<<"Enter no.of resources : ";
    cin>>r;
    char res[r];
    int inst[r];
    cout<<"Enter names and instances of resources : \n";
    cout<<"Resource\tInstance\n";
    for(int i=0;i<r;i++)
        cin>>res[i]>>inst[i];
    cout<<"Enter no.of processes : ";
    cin>>n;
    int max[n][r];
    cout<<"Enter the Allocation matrix :\n";
    cout<<"    ";
    for(int i=0;i<r;i++)
        cout<<res[i]<<" ";
    cout<<"\n";
    for(int i=0;i<n;i++)
    {
        cout<<"P"<<i<<"  ";
        for(int j=0;j<r;j++)
        {
            cin>>all[i][j];
        }
    }
    cout<<"Enter the Max matrix :\n";
    cout<<"    ";
    for(int i=0;i<r;i++)
        cout<<res[i]<<" ";
    cout<<"\n";
    for(int i=0;i<n;i++)
    {
        cout<<"P"<<i<<"  ";
        for(int j=0;j<r;j++)
        {
            cin>>max[i][j];
        }
    }
    for(int i=0;i<r;i++)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            sum+=all[j][i];
        }
        Available[i]=inst[i]-sum;
        // cout<<Available[i]<<" ";
    }
    // cout<<"\n";
    // cout<<"Need matrix : \n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<r;j++)
        {
            need[i][j]=max[i][j]-all[i][j];
            // cout<<need[i][j]<<" ";
        }
        // cout<<"\n";
    }
    cout<<"Is there any resource request? Y/N : ";
    char ch;
    cin>>ch;
    if(ch=='Y')
    {
        cout<<"Enter process no : ";
        int q;
        cin>>q;
        cout<<"Enter resource request : \n";
        int req[r];
        for(int i=0;i<r;i++)
            cout<<res[i]<<" ";
        cout<<"\n";
        for(int i=0;i<r;i++)
            cin>>req[i];
        for(int i=0;i<r;i++)
        {
            Available[i]=Available[i]-req[i];
            all[q][i]=all[q][i]+req[i];
            need[q][i]=need[q][i]-req[i];
        }
    }
    Safety(n,r);
}