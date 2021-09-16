#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#define _CRT_SECURE_NO_WARNINGS


void SelectionSort(int* array, int n){
    int tmp, j,min;
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

    return;
}

void InsertSort(int* array, int n){
    int tmp, j;
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

    return;
}

void RSSort(int* array, int n){
    int tmp, j, max;
    for (int i = 0; i < n-1; i++)
    {
        max = i;
        for (int j = i+1; j < n; j++)
        {
            if (array[j] > array[max])
            {
                max = j;
            }
        }
        tmp = array[i];
        array[i] = array[max];
        array[max] = tmp;
    }

    return;
}

void RISort(int* array, int n){
    int tmp, j;
    for (int i = 0; i < n-1; i++)
    {
        j = i;
         while (array[j] < array[j + 1] && j >= 0)
        {
            tmp = array[j];
            array[j] = array[j + 1];
            array[j + 1] = tmp;
            j--;
        }
    }

    return;
}
int main(void){
    int n;
    scanf("%d", &n);
    int *A = (int*)malloc(n * sizeof(int));
    int *B = (int*)malloc(n * sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < n; i++){
        A[i] = rand();
        B[i] = A[i];
    }


    LARGE_INTEGER ticksPerSec;
    LARGE_INTEGER start, end, diff;

    //선택정렬
    QueryPerformanceFrequency(&ticksPerSec);
    QueryPerformanceCounter(&start);
    SelectionSort(A, n);
    QueryPerformanceCounter(&end);
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("%.12f\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart));
    
    //삽입정렬
    QueryPerformanceFrequency(&ticksPerSec);
    QueryPerformanceCounter(&start);
    InsertSort(B, n);
    QueryPerformanceCounter(&end);
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("%.12f\n\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart));

    //정렬 정렬
    //선택정렬
    QueryPerformanceFrequency(&ticksPerSec);
    QueryPerformanceCounter(&start);
    SelectionSort(A, n);
    QueryPerformanceCounter(&end);
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("%.12f\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart));
    
    //삽입정렬
    QueryPerformanceFrequency(&ticksPerSec);
    QueryPerformanceCounter(&start);
    InsertSort(B, n);
    QueryPerformanceCounter(&end);
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("%.12f\n\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart));


    //역정렬 정렬
    //선택정렬
    QueryPerformanceFrequency(&ticksPerSec);
    QueryPerformanceCounter(&start);
    RSSort(A, n);
    QueryPerformanceCounter(&end);
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("%.12f\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart));
    
    //삽입정렬
    QueryPerformanceFrequency(&ticksPerSec);
    QueryPerformanceCounter(&start);
    RISort(B, n);
    QueryPerformanceCounter(&end);
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("%.12f\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart));
    
    return 0;
}