#include <stdio.h>
#include <stdlib.h>

int total = 0;

int main()
{
    int n, m, v1, v2, w, min = 9999, s1, s2;
    int G[101][101], B[101], P[101];
    scanf("%d %d", &n, &m);

    //배낭 초기화
    for (int i = 1; i <= n; i++)
    {
        P[i] = i;
    }

    //인접배열 초기화
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &v1, &v2, &w);
        G[v1][v2] = w;
        G[v2][v1] = w;
    }

    for (int edge = 0; edge < n - 1; edge++)
    {
        // int flag = 0;
        // for(int p=1;p<=n;p++){
        //     if(P[p]==1){
        //         flag++;
        //     }
        // }
        // if(flag == n){
        //     break;
        // }
        min = 9999;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if ((G[i][j] > 0 && G[i][j] < min) && (P[i] != P[j]))
                {
                    min = G[i][j];
                    v1 = i;
                    v2 = j;
                }
            }
        }
        printf(" %d", min);
        total += min;
        G[v1][v2] = -1;
        G[v2][v1] = -1;
        if (P[v1] < P[v2])
        {
            s1 = P[v1];
            s2 = P[v2];
        }
        else
        {
            s1 = P[v2];
            s2 = P[v1];
        }
        for (int i = 1; i <= n; i++)
        {
            if (P[i] == s2)
            {
                P[i] = s1;
            }
        }
    }
    printf("\n%d", total);

    return 0;
}
