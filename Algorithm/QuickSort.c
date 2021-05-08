#include <stdio.h>

void quickSort(int* array, int start, int end){
    if(start >= end) return;

    int key = start;
    int i = start + 1;
    int j = end;
    int tmp;

    while (1)
    {
        while (array[i] <= array[key] && i < end) //왼쪽부터 키 값보다 큰 값을 찾으러 떠나는 여행
        {
            i++;
        }
        while (array[j] >= array[key] && j > start) //오른쪽 부터 키 값보다 작은 값을 찾으러 떠나는 여행
        {
            j--;
        }
        if (i >= j) //만약 둘이 엇갈리면 키 값이 거기로 들어간다. 
        {
            tmp = array[key];
            array[key] = array[j];
            array[j] = tmp;
            break;
        }
        tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }

    quickSort(array, start, j);
    quickSort(array, j+1 , end);
}

int main(){
    int array[10];
    
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &array[i]);
    }  
    quickSort(array, 0 , 9);
    
     for (int i = 0; i < 10; i++)
    {
       printf("%d ", array[i]);
    } 

    return 0;
}