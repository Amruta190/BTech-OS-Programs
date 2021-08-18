#include<iostream>
using namespace std;
int main()
{
    int memory_size,page_size;
    cout<<"Enter the size of the memory : ";
    cin>>memory_size;
    cout<<"Enter page size : ";
    cin>>page_size;
    int n=memory_size/page_size;
    cout<<"No.of pages = "<<n<<"\n";
    int np;
    cout<<"Enter no.of processes : ";
    cin>>np;
    int i=1,j=0,pages,pt[np][10];
    while(i<=np)
    {
        cout<<"Enter no.of pages required for process-"<<i<<" : ";
        cin>>pages;
        if(j+pages<=n)
        {
            j+=pages;
            cout<<"Enter page table for process-"<<i<<" : ";
            for(int q=0;q<pages;q++)
                cin>>pt[i][q];
        }
        else
        {
            cout<<"Memory is full\n";
            break;
        }
        i++;
    }
    cout<<"Enter logical address : \n";
    cout<<"Process number : ";
    int k;
    cin>>k;
    cout<<"Page number : ";
    int l;
    cin>>l;
    cout<<"Offset : ";
    int offset;
    cin>>offset;
    int phyadd=(pt[k][l]*page_size)+offset;
    cout<<"Physical address is : "<<phyadd;
}