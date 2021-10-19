#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#define _CRT_SECURE_NO_WARNINGS
void merge(int** L, int l, int m, int r){
    int *A = *L;
    int *B;
    B = (int *)malloc(sizeof(int) * (r+1));
    int i = l;
    int k = l;
    int j = m + 1;
    while(i<=m && j<=r){
        if(A[i]<=A[j]){
            B[k] = A[i];
            k++;
            i++;
        }
        else{
            B[k] = A[j];
            k++;
            j++;
        }
    }
    while(i<=m){
        B[k] = A[i];
        k++;
        i++;
    }
    while(j<=r){
        B[k] = A[j];
        k++;
        j++;
    }
    for (k = l; k <= r;k++){
        A[k] = B[k];
    }
    free(B);
}

void rMergeSort(int**L,int l, int r){
    if(l<r){
        int m = (l + r) / 2;
        rMergeSort(L, l, m);
        rMergeSort(L, m + 1, r);
        merge(L, l, m, r);
    }
}

void mergeSort(int**L,int n){
    rMergeSort(L, 0, n - 1);
}

int findPivot(int l,int r){
    srand(time(NULL));
    return rand()%(r-l+1)+l;
}

void inPlacePartition(int **L,int l, int r, int k,int*a,int*b){
    int *A = (*L);
    int p = A[k];
    int tmp;

    tmp = A[k];
    A[k] = A[l];
    A[l] = tmp;
    int LT = l;
    int i = l+1;
    int GT = r;
    while(i<=GT){
        if(A[i]>p){
            tmp = A[i];
            A[i] = A[GT];
            A[GT] = tmp;
            GT--;
        }
        else if(A[i]<p){
            tmp = A[i];
            A[i] = A[LT];
            A[LT] = tmp;
            LT++;
        }
        else{
            i++;
        }
    }
    (*a) = LT;
    (*b) = GT;

    return;
}

void inPlaceQuickSort(int** L, int l, int r){
    if(l<r){
        int a, b;
        int k = findPivot(l, r);
        inPlacePartition(L, l, r, k,&a,&b);
        inPlaceQuickSort(L, l, a-1);
        inPlaceQuickSort(L, b+1, r);
    }
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

    //합병정렬
    QueryPerformanceFrequency(&ticksPerSec);
    QueryPerformanceCounter(&start);
    mergeSort(&A, n);
    QueryPerformanceCounter(&end);
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("%.12f\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart));
    
    //퀵정렬
    QueryPerformanceFrequency(&ticksPerSec);
    QueryPerformanceCounter(&start);
    inPlaceQuickSort(&B,0, n-1);
    QueryPerformanceCounter(&end);
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("%.12f\n\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart));


    return 0;
}