#include<iostream>
using namespace std;
int main()
{
    int i=0,flag=1,filled[100],index[100],index_blocks[100];
    for(int j=0;j<101;j++)
    {
        filled[j]=0;
        index[j]=0;
    }
    string names[100];
    while(flag)
    {
        int n,ind,j;
        cout<<"Enter file name : ";
        cin>>names[i];
        cout<<"Enter index block : ";
        cin>>ind;
        if(filled[ind]==1)
        {
            cout<<"Block is already filled\n";
            cout<<"File not allocated\n";
            i--;
        }
        else if(filled[ind]==0)
        {
            filled[ind]=1;
            cout<<"Enter no.of blocks in index block - "<<ind<<" : ";
            cin>>n;
            cout<<"Enter block numbers : ";
            for(j=0;j<n;j++)
                cin>>index[j];
            for(j=0;j<n;j++)
            {
                if(filled[index[j]]==0)
                    filled[index[j]]=1;
                else
                {
                    cout<<"Block already filled\n";
                    cout<<"File not allocated\n";
                    i--;
                    break;
                }
            }
            if(j==n)
            {
                index_blocks[i]=ind;
                cout<<"File allocated\n";
                cout<<"Blocks filled are : ";
                for(int k=0;k<n;k++)
                    cout<<index[k]<<" ";
            }
        }
        char ch;
        cout<<"\nEnter another file ? Y:N - ";
        cin>>ch;
        if(ch=='Y')
            flag=1;
        else if(ch=='N')
        {
            flag=0;
            cout<<"\n-----Allocated files are-----\nFile\tIndex block\n";
            for(int p=0;p<=i;p++)
                cout<<names[p]<<"\t"<<index_blocks[p]<<"\n";
        }
        i++;
    }
}