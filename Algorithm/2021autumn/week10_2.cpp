#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char command;
    int num, ad[6][6] = {0};
    ad[0][1] = 1;
    ad[1][0] = 1;
    ad[0][2] = 1;
    ad[2][0] = 1;
    ad[0][3] = 1;
    ad[3][0] = 1;
    ad[0][5] = 2;
    ad[5][0] = 2;
    ad[1][2] = 1;
    ad[2][1] = 1;
    ad[2][4] = 4;
    ad[4][2] = 4;
    ad[4][4] = 4;
    ad[4][5] = 3;
    ad[5][4] = 3;

    while (1)
    {
        scanf("%c", &command);
        if (command == 'a')
        {
            int tmp = 0;
            scanf("%d", &num);
            if (num > 6)
            {
                printf("-1\n");
                continue;
            }
            for (int i = 0; i < 6; i++)
            {
                if (ad[num - 1][i] != 0)
                {
                    tmp++;
                    printf(" %d %d", i + 1, ad[num - 1][i]);
                }
            }
            if (tmp == 0)
            {
                printf("-1");
            }
            printf("\n");
        }
        if (command == 'm')
        {
            int from, to, w;
            scanf("%d %d %d", &from, &to, &w);
            if (from > 6 || to > 6)
            {
                printf("-1\n");
                continue;
            }
            if ((ad[from - 1][to - 1] == 0 && w == 0) || (ad[to - 1][from - 1] == 0 && w == 0))
            {
                printf("-1\n");
                continue;
            }

            ad[from - 1][to - 1] = w;
            ad[to - 1][from - 1] = w;
        }
        if (command == 'q')
        {
            break;
        }
    }
    return 0;
}