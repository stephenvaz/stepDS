#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    printf("PARENT: %d\n", getpid());
    for (int i = 0; i < 2; i++)
    {
        fork();
        wait(NULL);
        fork();
        wait(NULL);
    }
    printf("|- CHILD: %d\n", getpid());
    return 0;
}