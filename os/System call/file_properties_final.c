#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

void informationSystemCalls()
{
    printf("Current process ID: %d\n", getpid());
    printf("Parent process ID: %d\n", getppid());
    printf("User ID: %d\n", getuid());
    printf("Effective User ID: %d\n", geteuid());
    printf("Group ID: %d\n", getgid());
    printf("Effective Group ID: %d\n", getegid());
}

int main()
{
    char *file_path = "test.txt";
    struct stat file_info;
    stat(file_path, &file_info);
    printf("\nName of file- %s", file_path);
    printf("\nDevice of file- %ld", file_info.st_dev);
    printf("\nInode of file- %ld", file_info.st_ino);
    printf("\nlink count of file- %ld", file_info.st_nlink);
    printf("\nMode of file- %d", file_info.st_mode);
    printf("\nOwner id of file- %d", file_info.st_uid);
    printf("\ngroup id of file- %d", file_info.st_gid);
    printf("\nSize of file- %ld", file_info.st_size);
    printf("\nblocks allocated(512) of file- %ld", file_info.st_blocks);
    printf("\nOptimal block size for IO- %ld\n", file_info.st_blksize);

    printf("\n\n\n");
    informationSystemCalls();
    return 0;
}