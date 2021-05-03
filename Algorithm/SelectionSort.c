#include <stdio.h>

int main()
{
    int array[10], tmp;

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = i; j < 10; j++)
        {
            if (array[j] < array[i])
            {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }

    for (int i = 0 ; i < 10 ; i++){
        printf("%d ",array[i]);
    }
}