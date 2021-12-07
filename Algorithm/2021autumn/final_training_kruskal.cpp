#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **G, *Sack, v1, v2, w, s1, s2, n, m, total;
    total = 0;

    scanf("%d %d", &n, &m);
    Sack = (int *)malloc(sizeof(int) * (n + 1));
    G = (int **)malloc(sizeof(int *) * (n + 1));

    for (int i = 0; i <= n; i++)
    {
        G[i] = (int *)malloc(sizeof(int) * (n + 1));
        Sack[i] = i;
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            G[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &v1, &v2, &w);
        G[v1][v2] = w;
        G[v2][v1] = w;
    }
    int i, j, min;
    for (int e = 0; e < n - 1; e++)
    {
        min = 99999;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (G[i][j] < min && G[i][j] != 0 && Sack[i] != Sack[j])
                {
                    min = G[i][j];
                    v1 = i;
                    v2 = j;
                    s1 = Sack[i];
                    s2 = Sack[j];
                }
            }
        }
        printf(" %d", min);
        total += min;
        G[v1][v2] = 0;
        G[v2][v1] = 0;
        if (s1 < s2)
        {
            for (i = 1; i <= n; i++)
            {
                if (Sack[i] == s2)
                {
                    Sack[i] = s1;
                }
            }
        }
        else
        {
            for (i = 1; i <= n; i++)
            {
                if (Sack[i] == s1)
                {
                    Sack[i] = s2;
                }
            }
        }
    }
    printf("\n%d", total);

    return 0;
}