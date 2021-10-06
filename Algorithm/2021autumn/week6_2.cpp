#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void binarySearch(int *A, int k, int l, int r)
{
    int mid = (l + r) / 2;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (k > A[mid])
        {
            if (l != r)
            {
                l = mid + 1;
            }
            else
            {
                mid++;
                break;
            }
        }
        else if (k < A[mid])
        {
            r = mid - 1;
        }
        else
        {
            break;
        }
    }
    printf(" %d", mid);
}

int main()
{
    int n, k, input, i;
    int *array;
    scanf("%d %d", &n, &k);
    array = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &input);
        array[i] = input;
    }
    binarySearch(array, k, 0, n - 1);
}