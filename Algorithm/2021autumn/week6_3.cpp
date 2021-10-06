#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, n, i, mid;
    char input;
    scanf("%d %d %d", &a, &b, &n);
    for (i = 0; i <= n; i++)
    {
        mid = (a + b) / 2;
        scanf("%c", &input);
        if (input == 'Y')
        {
            a = mid + 1;
        }
        if (input == 'N')
        {
            b = mid;
        }
        if (a == b)
        {
            printf("%d", a);
        }
    }
}