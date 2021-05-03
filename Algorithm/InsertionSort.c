#include <stdio.h>

int main()
{
    int array[10] = {4, 1, 5, 2, 6, 10, 9, 7, 8, 3};
    int tmp, j;

    for (int i = 0; i < 9; i++)
    {
        j = i;
        while (array[j] > array[j + 1])
        {
            tmp = array[j];
            array[j] = array[j + 1];
            array[j + 1] = tmp;
            j--;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}