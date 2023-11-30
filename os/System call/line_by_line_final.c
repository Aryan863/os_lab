#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int fd = open("test.txt", O_RDONLY);
    // int fd1 = creat("copy.txt", S_IRUSR | S_IWUSR);
    // fd1 = open("copy.txt", O_APPEND | O_CREAT);
    int fd1 = open("copy.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

    char buffer[100];
    char line_buff[100];
    ssize_t buff_size;
    buff_size = read(fd, buffer, sizeof(char) * 100);
    printf("\nCharacter by character- ");
    for (int i = 0, j = 0; i < buff_size; i++)
    {
        printf(" %c", buffer[i]);
        // write(fd1, &buffer[i], sizeof(char));   //writing character by character
        line_buff[j] = buffer[i];
        j += 1;
        if (buffer[i] == '\n')
        {
            line_buff[++j] = '\0';
            printf("\n1 line completed");
            printf("\nLine = %s ", line_buff);
            write(fd1, line_buff, strlen(line_buff)); // writing character line by line
            j = 0;
        }
    }

    return 0;
}