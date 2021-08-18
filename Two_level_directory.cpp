#include <iostream>
using namespace std;
int main()
{
    string st,str;
    string names[100], mat[100][100];
    for(int p=0;p<101;p++)
        for(int q=0;q<101;q++)
            mat[p][q]="0";
    int i = 0,j;
    while (true)
    {
        cout << "\nSelect an option : \n";
        cout << "1. Create a directory\t2. Create a file\n3. Delete a directory\t4. Delete a file\n5. Search a directory\t6. Search a file\n7. Display\t8. Exit\n";
        int op, flag = 0,x=-1;
        cin >> op;
        switch (op)
        {
        case 1:
            cout << "Enter directory name : ";
            cin >> names[i];
            cout << "Directory " << names[i++] << " is created\n";
            break;
        case 2:
            cout << "Enter directory name : ";
            cin>>st;
            // int j;
            for(j=0;j<i;j++)
            {
                if(names[j]==st)
                {
                    x=j;
                    break;
                }
            }
            if(x==-1)
                cout<<"Directory "<<st<<" is not found\n";
            else
            {
                cout << "Enter file name : ";
                cin >> st;
                for(j=0;j<i;j++)
                {
                    if(j==x)
                    {
                        int z=0;
                        while(mat[x][z]!="0")
                            z++;
                        mat[x][z]=st;
                        break;
                    }
                }
                cout << "File " << st << " is created\n";
            }
            break;
        case 3:
            cout << "Enter directory name : ";
            cin>>st;
            flag=0;
            for(j=0;j<i;j++)
            {
                if(names[j]==st)
                {
                    flag=1;
                    int z=0;
                    while(mat[j][x]!="0")
                    {
                        mat[j][x]="0";
                        z++;
                    }
                    for(int k=j;k<i;k++)
                    {
                        z=0;
                        names[k]=names[k+1];
                        while(mat[k][z]!="0" && mat[k-1][z]!="0")
                        {
                            mat[k][z]=mat[k+1][z];
                            z++;
                        }
                    }
                    i--;
                    cout<<"Directory "<<st<<" is deleted\n";
                    break;
                }
            }
            if(flag==0)
                cout<<"Directory "<<st<<" is not found\n";
            break;
        case 4:
            cout << "Enter directory name : ";
            cin>>st;
            for(j=0;j<i;j++)
            {
                if(names[j]==st)
                {
                    x=j;
                    break;
                }
            }
            if(x==-1)
                cout<<"Directory "<<st<<" is not found\n";
            else
            {
                cout << "Enter file name : ";
                cin >> st;
                flag=0;
                for(j=0;j<i;j++)
                {
                    if(mat[x][j]==st) 
                    {
                        flag=1;
                        int z=j;
                        while(mat[x][z]!="0")
                        {
                            mat[x][z]=mat[x][z+1];
                            z++;
                        }
                        cout << "File " << st << " is deleted\n";
                        break;
                    }
                }
                if(flag==0)
                    cout<<"File "<<st<<" is not found\n";
            }
            break;
        case 5:
            cout << "Enter directory name : ";
            cin>>st;
            for(j=0;j<i;j++)
            {
                if(names[j]==st)
                {
                    x=j;
                    cout<<"Directory "<<st<<" is found\n";
                    break;
                }
            }
            if(x==-1)
                cout<<"Directory "<<st<<" is not found\n";
            break;
        case 6:
            cout << "Enter directory name : ";
            cin>>st;
            for(j=0;j<i;j++)
            {
                if(names[j]==st)
                {
                    x=j;
                    break;
                }
            }
            if(x==-1)
                cout<<"Directory "<<st<<" is not found\n";
            else
            {
                cout << "Enter file name : ";
                cin >> st;
                flag=0;
                for(j=0;j<i;j++)
                {
                    if(mat[x][j]==st) 
                    {
                        flag=1;
                        cout << "File " << st << " is found\n";
                        break;
                    }
                }
                if(flag==0)
                    cout<<"File "<<st<<" is not found\n";
            }
            break;
        case 7:
            if(i==0)
                cout<<"Empty\n";
            else
            {
                cout<<"Directory\tFiles\n";
                for(j=0;j<i;j++)
                {
                    cout<<"   "<<names[j]<<"  \t";
                    int z=0;
                    while(mat[j][z]!="0")
                    {
                        cout<<mat[j][z]<<" ";
                        z++;
                    }
                    cout<<"\n";
                }
            }
            break;
        case 8:
            exit(0);
        default:
            cout << "Enter correct option!\n";
        }
    }
}