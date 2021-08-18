#include<iostream>
using namespace std;
int main()
{
    string names[100];
    int i=0,flag=1,arr[100][2],links[100],var,var2,tmp;
    for(int j=0;j<101;j++)
        links[j]=-1;
    while(flag)
    {
        cout<<"Enter file name : ";
        cin>>names[i];
        cout<<"Enter start index : ";
        cin>>arr[i][0];
        var=arr[i][0];
        while(var!=-1)
        {   
            if(links[var]==-1)
            {
                cout<<"Enter block no in index-"<<var<<" : ";
                cin>>var2;
                links[var]=var2;
                tmp=var;
                var=var2;
            }
            else
            {
                cout<<"Block already filled\n";
                cout<<"File not allocated\n";
                i--;
                break;
            }
        }
        if(var==-1)
        {
            arr[i][1]=tmp;
            cout<<"File allocated\n";
            cout<<"Blocks filled are : ";
            var=arr[i][0];
            do
            {
                if(links[var]!=-1)
                    cout<<var<<" ";
                var=links[var];
            }while(var!=-1);
        }
        char ch;
        cout<<"\nEnter another file ? Y:N - ";
        cin>>ch;
        if(ch=='Y')
            flag=1;
        else if(ch=='N')
        {
            flag=0;
            cout<<"\n-----Allocated files are-----\nFile\tStart\tEnd\n";
            for(int p=0;p<=i;p++)
                cout<<names[p]<<"\t"<<arr[p][0]<<"\t"<<arr[p][1]<<"\n";
        }
        i++;
    }
}