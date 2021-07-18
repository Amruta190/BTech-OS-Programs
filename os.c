#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
    if(fork()==0)
        printf("1 2 3\n");
    else    
    {
        wait(NULL);
        printf("a b c\n");
    }
    return 0;
}