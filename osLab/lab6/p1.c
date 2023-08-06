#include<stdio.h>
#include<sys/file.h>
#include<unistd.h>

int main()
{
    FILE *fp = fopen("p1.txt", "w");
    int fd = open("p1.txt", O_WRONLY);
    printf("Process 1 locking file p1.txt in exclusive mode lock for 10 seconds\n");
    flock(fd, LOCK_EX);
    fseek(fp, 0, SEEK_SET);
    fprintf(fp, "Hello World! from process 1");
    sleep(10);
    printf("Unlocking file p1.txt");
    flock(fd, LOCK_UN);
    fclose(fp);
    return 0;
}