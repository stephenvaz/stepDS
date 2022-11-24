#include <stdio.h>
#include <math.h>

void calcDNMap(int memSize, int cacheSize, int blockSize)
{
    int nPages = (int)log2f((pow(2, 20) * memSize) / (cacheSize));
    int nlines = (int)log2f((pow(2, 10) * cacheSize) / blockSize);
    int nBlocks = (int)log2f(blockSize);
    printf("\nmemSize: %d GB, cacheSize: %d KB, blockSize: %d B\nNo. of pages = %d\n", memSize, cacheSize, blockSize, nPages);
    printf("No. of lines = %d\n", nlines);
    printf("No. of blocks = %d\n", nBlocks);
}

void userInput(int *memSize, int *cacheSize, int *blockSize)
{
    printf("Enter memory size (GB): ");
    scanf("%d", memSize);
    printf("Enter cache size (KB): ");
    scanf("%d", cacheSize);
    printf("Enter block size (Bytes): ");
    scanf("%d", blockSize);
}

int main()
{
    int memSize, cacheSize, blockSize, n;
    while (1)
    {
        printf("1. Direct Mapping\n2. N Way Associative Mapping\n3. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            userInput(&memSize, &cacheSize, &blockSize);
            printf("\nDirect Mapping\n");
            calcDNMap(memSize, cacheSize, blockSize);
            break;
        case 2:
            userInput(&memSize, &cacheSize, &blockSize);
            printf("Enter N: ");
            scanf("%d", &n);
            printf("\n%d Way Associative Mapping\n", n);
            calcDNMap(memSize, cacheSize / n, blockSize);
            break;
        case 3:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}