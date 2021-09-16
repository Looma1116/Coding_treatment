#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    int tmp, j;
    int n;
    scanf("%d", &n);
    int *array = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n;i++){
        scanf("%d", &array[i]);
    }
    for (int i = 0; i < n-1; i++)
    {
        j = i;
         while (array[j] > array[j + 1] && j >= 0)
        {
            tmp = array[j];
            array[j] = array[j + 1];
            array[j + 1] = tmp;
            j--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}