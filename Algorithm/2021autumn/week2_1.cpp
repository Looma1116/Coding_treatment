#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

//선택정렬
int main()
{
    
    int tmp, j, min;
    int n;
    scanf("%d", &n);
    int *array = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n;i++){
        scanf("%d", &array[i]);
    }
    for (int i = 0; i < n-1; i++)
    {
        min = i;
        for (int j = i+1; j < n; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        tmp = array[i];
                array[i] = array[min];
                array[min] = tmp;
    }

    for (int i = 0; i < n; i++)
    {
        printf(" %d", array[i]);
    }
    return 0;
}