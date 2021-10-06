#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *A, int k, int l, int r)
{
    int mid = (l + r) / 2;
    if (l > r)
    {
        return -1 * l;
    }
    if (A[mid] == k)
    {
        return mid;
    }
    if (A[mid] > k)
    {
        binarySearch(A, k, l, mid - 1);
    }
    else
    {
        binarySearch(A, k, mid + 1, r);
    }
}

int main()
{
    int n, k1, k2, input, i;
    int *array;
    scanf("%d %d %d", &n, &k1, &k2);
    array = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &input);
        array[i] = input;
    }
    int a = binarySearch(array, k1, 0, n - 1);
    int b = binarySearch(array, k2, 0, n - 1);
    // printf("a: %d b: %d\n", a, b);
    if (n == 0)
    {
        printf(" -1");
        return 0;
    }
    if (a == b && b < 0)
    {
        printf(" -1");
        return 0;
    }
    else
    {
        if (b < 0)
        {
            b = b * -1;
            b--;
        }
        if (a < 0)
        {
            a = a * -1;
        }
        for (i = a; i <= b; i++)
        {
            printf(" %d", i);
        }
    }

    return 0;
}