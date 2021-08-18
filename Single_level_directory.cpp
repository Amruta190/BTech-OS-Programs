#include <iostream>
using namespace std;
int main()
{
    cout << "Enter directory name : ";
    string dir, st;
    cin >> dir;
    string names[100];
    int i = 0, j;
    while (true)
    {
        cout << "\nSelect an option : \n";
        cout << "1. Create a file\t2. Delete a file\t3. Search a file\t4. Display all files\t5. Exit\n";
        int op, flag = 0;
        cin >> op;
        switch (op)
        {
        case 1:
            cout << "Enter file name : ";
            cin >> names[i];
            cout << "File " << names[i++] << " is created\n";
            break;
        case 2:
            if (i == 0)
                cout << "Directory " << dir << " is empty\n";
            else
            {
                cout << "Enter file name : ";
                cin >> st;
                for (j = 0; j < i; j++)
                {
                    if (names[j] == st)
                    {
                        for (int k = j + 1; k < i; k++)
                            names[k - 1] = names[k];
                        i--;
                        flag = 1;
                        cout << "File " << st << " is deleted\n";
                        break;
                    }
                }
                if (flag == 0)
                    cout << "File " << st << " is not found\n";
            }
            break;
        case 3:
            if (i == 0)
                cout << "Directory " << dir << " is empty\n";
            else
            {
                cout << "Enter file name : ";
                cin >> st;
                for (j = 0; j < i; j++)
                {
                    if (names[j] == st)
                    {
                        flag = 1;
                        cout << "File " << st << " is found\n";
                        break;
                    }
                }
                if (flag == 0)
                    cout << "File " << st << " is not found\n";
            }
            break;
        case 4:
            if (i == 0)
                cout << "Directory " << dir << " is empty\n";
            else
            {
                cout << "The files in directory " << dir << " are : ";
                for (int j = 0; j < i; j++)
                    cout << names[j] << " ";
            }
            break;
        case 5:
            exit(0);
        default:
            cout << "Enter correct option!\n";
        }
    }
}