#include <stdio.h>
#include <sys/file.h>
#include <unistd.h>

int main()
{
    char str[255];
    FILE *fp;
    fp = fopen("./p2.txt", "r");
    printf("\nTrying Share lock");
    int fd = open("./txt.txt", O_RDONLY);
    sleep(2);
    flock(fd, LOCK_SH);
    fgets(str, sizeof(str), fp);
    printf("\n%s", str);
    printf("\nReleasing Share lock");
    flock(fd, LOCK_UN);
    fclose(fp);
}