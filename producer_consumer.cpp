#include <iostream>
using namespace std;
int mutex = 1, in = 0, out = 0, full = 0, empty = 10, buffer_size = 10, buffer[10];
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
void producer(int k)
{
    // do{
    empty = wait(empty);
    mutex = wait(mutex);
    // while ((in+1)%buffer_size == out)
    // ;
    buffer[in] = k;
    cout << "Item " << k << " is produced\n";
    in = (in + 1) % buffer_size;
    mutex = signal(mutex);
    full = signal(full);
    // }while(true);
}
void consumer()
{
    // do{
    full = wait(full);
    mutex = wait(mutex);
    // while (in == out)
    // ;
    cout << "Item " << buffer[out] << " is consumed\n";
    buffer[out] = 0;
    out = (out + 1) % buffer_size;
    mutex = signal(mutex);
    empty = signal(empty);
    // }while(true);
}
void print()
{
    cout << "Full = " << full << "\n";
    cout << "Empty = " << empty << "\n";
}
int main()
{
    cout << "Buffer_size is 10\n";
    while (true)
    {
        int n, k;
        cout << "Select one option\n1. Producer\t2. Consumer\t3. Print buffer \t4. Exit\n";
        cin >> n;
        switch (n)
        {
        case 1:
            if (empty != 0 && mutex == 1)
            {
                cout << "Enter item : ";
                cin >> k;
                producer(k);
                print();
            }
            else
                cout << "Buffer is full\n";
            break;
        case 2:
            if (full != 0 && mutex == 1)
            {
                consumer();
                print();
            }
            else
                cout << "Buffer is empty\n";
            break;
        case 3:
        {
            if (full == 0)
                cout << "Buffer is empty\n";
            else
            {
                // cout<<"Buffer : ";
                // for(int i=out;i!=in;i=(i+1)%10)
                //     cout<<buffer[i]<<" ";
                // cout<<"\n";
                cout << "Buffer : ";
                for (int i = 0; i < 10; i++)
                {
                    if(buffer[i]!=0)
                        cout << buffer[i] << " ";
                }
                cout << "\n";
            }
        }
        break;
        case 4:
            exit(0);
        default:
            cout << "Enter correct input!\n";
        }
    }
}