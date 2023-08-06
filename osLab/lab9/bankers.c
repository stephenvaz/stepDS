#include <stdio.h>

int main()
{
    int n, m, i, j, k;
    printf("\nNumber of processes: ");
    scanf("%d", &n);
    printf("\nNumber of resources: ");
    scanf("%d", &m);
    int alloc[n][m], max[n][m], need[n][m], avail[m];
    printf("\nAllocation Matrix:\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d: ", i);
        for (j = 0; j < m; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("\nMax Matrix:\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d: ", i);
        for (j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nAvailable Resources:\n");
    for (j = 0; j < m; j++)
    {
        scanf("%d", &avail[j]);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    int f[n];
    for (k = 0; k < n; k++)
    {
        f[k] = 0;
    }

    int ans[n], ind = 0;

    int y = 0;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {
                int flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                    {
                        avail[y] += alloc[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
    }

    int isSafe = 1;
    for (i = 0; i < n; i++)
    {
        if (f[i] == 0)
        {
            isSafe = 0;
            printf("\nSystem is unsafe\n");
            break;
        }
    }

    if (isSafe == 1)
    {
        printf("\nSafe Sequence: \n");
        for (i = 0; i < n - 1; i++)
        {
            printf("P%d -> ", ans[i]);
        }
        printf("P%d\n", ans[n - 1]);
    }

    return 0;
}