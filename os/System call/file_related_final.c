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
    int fd;
    char buffer1[100];
    char buffer2[100];

    fd = creat("test.txt", S_IRUSR | S_IWUSR);
    if (fd == -1)
        printf("\nError in file creation");

    strcpy(buffer1, "Hello There.\n");

    write(fd, buffer1, sizeof(char) * 20);

    close(fd);

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
        printf("\nError in file opening");

    read(fd, buffer2, sizeof(char) * 100);
    printf("\n Read from file-> %s", buffer2);

    close(fd);

    struct stat file_info;
    int i = stat("test.txt", &file_info);
    if (i == -1)
        printf("\nError");
    printf("\nFile info(file size)= %ld", file_info.st_size);

    i = link("test.txt", "hard_link.txt");
    if (i == -1)
        printf("\nLink failed");

    i = unlink("hard_link.txt");
    if (i == -1)
        printf("\nUnLink failed");

    return 0;
}