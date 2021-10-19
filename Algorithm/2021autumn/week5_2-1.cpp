#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int main(){
    int *A;
    int n, data;
    scanf("%d", &n);
    A = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++){
        scanf("%d", &data);
        A[i] = data;
    }

    inPlaceQuickSort(&A, 0, n-1);
    for (int i = 0; i < n; i++){
        printf(" %d", A[i]);
    }
    return 0;
}
