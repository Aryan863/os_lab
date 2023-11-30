#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    int fd[2];
    pipe(fd);
    int id = fork();
    if (id == 0)
    {
        printf("\nHi from child ");
        char buff[100];
        // printf("\nEnter message- ");
        // fgets(buff, 100, stdin);
        // strcpy(buff, "Hello there");
        char *a = "How are you";
        close(fd[0]);
        write(fd[1], a, strlen(a));
        // write(fd[1], a, sizeof(char) * 100);
        close(fd[1]);
        exit(0);
    }
    else
    {
        int status;
        wait(&status);
        printf("\nHi from parent ");
        char buff1[100];
        close(fd[1]);
        read(fd[0], buff1, sizeof(char) * 100);
        close(fd[0]);
        printf("\nGot from child %s", buff1);
    }
    return 0;
}