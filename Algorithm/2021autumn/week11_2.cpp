#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int Q[101];
int head = -1, tail = -1;

void initQ()
{
    head = 0;
    tail = 0;
}

void clearQ()
{
    head = tail;
}

int deQ()
{
    int i;
    if (head == tail)
    {
        return -1;
    }
    i = Q[head];
    ++head;
    head %= 101;
    return i;
}

void enQ(int value)
{
    if ((tail + 1) % 101 == head)
    {
        printf("full Queue\n");
        return;
    }
    Q[tail] = value;
    ++tail;
    tail %= 101;
    return;
}

int main()
{
    char command;
    int num, ad[101][101], visit[101], n, m, s, ver1, ver2, i, node;
    scanf("%d %d %d", &n, &m, &s);
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &ver1, &ver2);
        ad[ver1][ver2] = 1;
        ad[ver2][ver1] = 1;
    }

    enQ(s);
    visit[s] = 1;
    printf("%d\n", s);
    while (head != tail)
    {
        node = deQ();
        for (i = 1; i <= n; i++)
        {
            if (ad[node][i] == 1 && visit[i] == 0)
            {
                enQ(i);
                printf("%d\n", i);
                visit[i] = 1;
            }
        }
    }

    return 0;
}