#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void singleMode(int *A, int n)
{
    int flag = 0, direction = 0, max, min;

    if (n < 2)
    {
        printf(" 0");
        return;
    }
    if (A[0] < A[1])
    {
        direction = 1;
    }
    else if (A[0] > A[1])
    {
        direction = -1;
    }

    for (int i = 2; i < n; i++)
    {
        if (direction == -1 && A[i - 1] < A[i])
        {
            flag++;
            direction = 1;
            min = A[i - 1];
        }
        if (direction == 1 && A[i - 1] > A[i])
        {
            flag++;
            direction = -1;
            max = A[i - 1];
        }
    }
    if (flag == 1)
    {
        if (direction == -1)
        {
            printf(" 1 %d", max);
        }
        else
        {
            printf(" -1 %d", min);
        }
    }
    else
    {
        printf(" 0");
    }
    return;
}
int main()
{
    int n, i, input;
    int *array;
    scanf("%d", &n);
    array = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &input);
        array[i] = input;
    }
    singleMode(array, n);
    return 0;
}