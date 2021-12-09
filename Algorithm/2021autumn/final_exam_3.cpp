#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, k, v1, v2, w, G[101][101] = {0}, flag;
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &v1, &v2, &w);
        G[v1][v2] = w;
        G[v2][v1] = w;
    }
    for (int i = 0; i < k; i++)
    {
        flag = 0;
        scanf("%d", &v1);
        for (int j = 1; j <= n; j++)
        {
            if (G[v1][j] != 0)
            {
                flag++;
            }
        }
        if (flag == 0)
        {
            printf(" -1"); //정점 없으면 -1
        }
        else //인접 간선 돌면서 정점이랑 가중치 출력
        {
            for (int j = 1; j <= n; j++)
            {
                if (G[v1][j] != 0)
                {
                    printf(" %d %d", j, G[v1][j]);
                }
            }
        }
        printf("\n");
    }

    return 0;
}