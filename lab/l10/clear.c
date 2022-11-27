#include<stdio.h>
#include<stdlib.h>


void clear() {
    printf("\033[2J\033[1;1H");
}

int main()
{
    printf("Hello World");
    getchar();
    clear();
    return 0;
}