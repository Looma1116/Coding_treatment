#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char command;
    int num, ad[101][101], visit[101], n, m, s, ver1, ver2, i, L1[101], L2[101];
    scanf("%d %d %d", &n, &m, &s);
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &ver1, &ver2);
        ad[ver1][ver2] = 1;
        ad[ver2][ver1] = 1;
    }
    visit[s] = 1;
    printf("%d\n", s);
    for (i = 1; i <= n; i++)
    {
        if (ad[s][i] == 1 && visit[i] == 0)
        {
            visit[i] = 1;
            printf("%d\n", i);
        }
    }

    return 0;
}