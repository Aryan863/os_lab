#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
    int x = 3;
    int pid = fork();
    if (pid == 0)
    {
        printf("Hi from child process\n");
        x = x + 10;
        printf("\nValue of x in child process= %d", x);
        exit(0);
        }
    else
    {
        int status;
        printf("Hi from parent process\n");
        printf("The value of x in parent process= %d\n", x);
        wait(&status);
    }
    return 0;
}
